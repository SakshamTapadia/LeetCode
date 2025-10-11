class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> freq;
        for (int p : power) freq[p] += p; 

        vector<int> vals;
        for (auto &it : freq) vals.push_back(it.first);
        sort(vals.begin(), vals.end());

        int n = vals.size();
        vector<long long> dp(n, 0);

        for (int i = 0; i < n; i++) {
            long long take = freq[vals[i]];

            int j = i - 1;
            while (j >= 0 && vals[j] >= vals[i] - 2) j--;

            if (j >= 0) take += dp[j];

            long long skip = (i > 0 ? dp[i-1] : 0);
            dp[i] = max(skip, take);
        }

        return dp[n-1];
    }
};