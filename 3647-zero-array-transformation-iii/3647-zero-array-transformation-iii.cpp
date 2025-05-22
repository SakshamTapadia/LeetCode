#pragma clang attribute push ([[gnu::target("sse2,sse3,sse4.1,sse4.2,avx,avx2,popcnt,fma,bmi,bmi2,lzcnt")]], apply_to=function)
#include <ranges>
namespace {
    const char _ = []{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
    using u8  = uint8_t;
    using u16 = uint16_t;
    using u32 = uint32_t;
    using u64 = uint64_t;

    constexpr u32 N = 100'000;
    using pii = pair<u32, u32>;

    pii q_[N];
    pii tmp_[N];
    u32 cnt[1u << 9];

    template<u32 W, u32 B>
    pii* cntsort(u32 n) {
        constexpr u32 C = 1 << W, M = C - 1;
        auto a = q_, b = tmp_;
        for (u32 s = 0; s < B; s += W) {
            fill_n(cnt, C, 0);
            for (u32 i = 0; i < n; ++i) ++cnt[(a[i].first >> s) & M];
            for (u32 i = 1; i < C; ++i) cnt[i] += cnt[i - 1];
            for (u32 i = n; i--; ) b[--cnt[(a[i].first >> s) & M]] = a[i];
            swap(a, b);
        }
        return a;
    }

    pii* cntsort(u32 n, u32 mx) {
        if (n < 200) {
            ranges::sort(q_, q_ + n, {}, &pii::first);
            return q_;
        }
        if (mx < (1u << 9))
            return cntsort<9, 9>(n);
        return cntsort<9, 17>(n);
    }

}

class Solution {
public:
    int maxRemoval(vector<int>& nums_, vector<vector<int>>& queries) {
        const u32 n = nums_.size(), m = queries.size();
        const auto nums = (u32*)nums_.data();
        assert(n && m);
        for (u32 i = 0; i < m; ++i)
            q_[i] = {(u32)queries[i][0], (u32)queries[i][1]};
        auto q = cntsort(m, n - 1);
        auto pq = (u32*)(q == q_ ? tmp_ : q_);
        auto cnt = pq + N;
        fill_n(cnt, n, 0);
        u32 qn = 0, acc = 0, ans = 0;
        for (u32 i = 0, j = 0; i < n; ++i) {
            for (; j < m && q[j].first == i; ++j) {
                pq[qn++] = q[j].second;
                push_heap(pq, pq + qn);
            }
            if ((int)qn < (int)(nums[i] - acc)) return -1;
            while (acc < nums[i]) {
                if (pq[0] < i) return -1;
                ++cnt[pq[0]];
                ++acc;
                ++ans;
                pop_heap(pq, pq + qn--);
            }
            acc -= cnt[i];
            if (qn && pq[qn - 1] <= i) --qn;
        }
        return m - ans;
    }
};

#pragma clang attribute pop