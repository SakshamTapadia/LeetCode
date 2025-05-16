class Solution {
public:
    bool hamming1(const string& s, const string& t){
        const int sz = s.size();
        if (sz != t.size()) return false;
        int diff = 0;
        for (int i = 0; i < sz && diff < 2; i++)
            diff += s[i] != t[i];
        return diff == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        const int n = words.size();
        int maxLen = 0, pos = -1;
        vector<int> dp(n, 1), prev(n, -1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(groups[i] != groups[j] && hamming1(words[i], words[j])){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if(dp[i] > maxLen){
                maxLen = dp[i];
                pos = i;
            }
        }
        vector<string> ans;
        for(; pos != -1; pos = prev[pos]){
            ans.push_back(words[pos]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};