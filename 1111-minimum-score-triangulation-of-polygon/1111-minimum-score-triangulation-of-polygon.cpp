class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
    int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    int score = dp[i][k] + dp[k][j] + values[i] * values[k] * values[j];
                    dp[i][j] = min(dp[i][j], score);
                }
            }
        }
        return dp[0][n-1];    
    }
};