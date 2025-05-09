#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1000000007;
 
// Fast modular exponentiation.
long long modpow(long long a, long long b) {
    long long res = 1;
    while(b){
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
 
class Solution {
public:
    int countBalancedPermutations(string num) {
        int n = num.size();
        // E is the number of even indices; O is the number of odd indices.
        int E = (n + 1) / 2;
        int O = n - E;
 
        // Count frequency of each digit.
        vector<int> cnt(10, 0);
        for (char c : num)
            cnt[c - '0']++;
 
        // Precompute factorials and inverse factorials (mod MOD) up to n.
        vector<long long> fact(n+1, 1), invf(n+1, 1);
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i-1] * i % MOD;
        }
        invf[n] = modpow(fact[n], MOD - 2);
        for (int i = n; i > 0; i--) {
            invf[i-1] = invf[i] * i % MOD;
        }
 
        // Maximum possible absolute difference in digit sums.
        int totalS = 0;
        for (int d = 0; d < 10; d++)
            totalS += d * cnt[d];
 
        // dp array dimensions.
        // We shift difference by offset = totalS so that indices run from 0 to D-1.
        int D = 2 * totalS + 1, offset = totalS;
 
        // dp[k][delta] = weighted count (with division by factorials) for having used k even positions and
        // a difference of (delta - offset). Initially, no even slot is filled and difference is 0.
        vector<vector<long long>> dp(E+1, vector<long long>(D, 0));
        dp[0][offset] = 1;
        vector<vector<long long>> nxt(E+1, vector<long long>(D, 0));
 
        // Process digits 0 to 9 in order.
        for (int d = 0; d < 10; d++) {
            int c = cnt[d];
            // Precompute weight for assigning ke copies to even indices and (c - ke) to odd ones.
            // The weight is 1/(ke!*(c-ke)!) which later will be “fixed” by multiplying with fact[E]*fact[O].
            vector<long long> weight(c+1, 0);
            for (int ke = 0; ke <= c; ke++) {
                weight[ke] = invf[ke] * invf[c - ke] % MOD;
            }
 
            // Clear the nxt dp state.
            for (int i = 0; i <= E; i++) {
                fill(nxt[i].begin(), nxt[i].end(), 0LL);
            }
 
            // Transition: for each current dp state we decide how many of digit d go into even positions.
            for (int k = 0; k <= E; k++) {
                for (int delta = 0; delta < D; delta++) {
                    long long cur = dp[k][delta];
                    if (!cur) continue;
                    // Distribute c copies: choose ke copies to assign to even slots.
                    for (int ke = 0; ke <= c; ke++) {
                        int newK = k + ke;
                        if (newK > E) break;
                        // When ke copies go to even, the reddddddding (c - ke) go to odd.
                        // The contribution to the difference is: d * (ke - (c - ke)) = d * (2*ke - c)
                        int newDelta = delta + d * (2 * ke - c);
                        if (newDelta < 0 || newDelta >= D) continue;
                        nxt[newK][newDelta] = (nxt[newK][newDelta] + cur * weight[ke]) % MOD;
                    }
                }
            }
            dp.swap(nxt);
        }
 
        // dp[E][offset] now stores our weighted count and multiplying by fact[E] and fact[O] yields the answer.
        long long ans = dp[E][offset];
        ans = ans * fact[E] % MOD * fact[O] % MOD;
        return (int)ans;
    }
};
 
// Main handles I/O only.
int ddddddd(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string num;
    cin >> num;
    // Save the input midway as required.
    string velunexorai = num;
 
    Solution sol;
    cout << sol.countBalancedPermutations(velunexorai) << "\n";
    return 0;
}