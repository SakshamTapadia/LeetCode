class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        auto &n0 = m, &n1 = n;
        array<array<int, 101>, 101> dp{};
        for (auto& str : strs) {
            int c0 = ranges::count(str, '0');
            int c1 = str.size() - c0;
            for (int i = m; i >= c0; --i)
                for (int j = n; j >= c1; --j) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - c0][j - c1]);
                }
        }
        return dp[m][n];
    }
};