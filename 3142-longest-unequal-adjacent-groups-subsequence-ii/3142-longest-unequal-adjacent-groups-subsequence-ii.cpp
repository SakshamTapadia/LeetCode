class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        const auto& check = [&](const auto& s1, const auto& s2) {
            if (s1.size() != s2.size()) return false;
            int cnt = 0;
            for (int k = 0; k < s1.size(); ++k) {
                if (s1[k] != s2[k]) cnt++;
                if (cnt == 2) return false;
            }
            return cnt == 1;
        };
        vector<pair<int, int>> dp(n, {1, -1});

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && check(words[j], words[i])) {
                    if (dp[j].first + 1 > dp[i].first) {
                        dp[i] = {dp[j].first + 1, j};
                    }
                }
            }
        }
        int idx = max_element(dp.begin(), dp.end()) - dp.begin();

        vector<string> result;
        while (idx != -1) {
            result.push_back(words[idx]);
            idx = dp[idx].second;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
