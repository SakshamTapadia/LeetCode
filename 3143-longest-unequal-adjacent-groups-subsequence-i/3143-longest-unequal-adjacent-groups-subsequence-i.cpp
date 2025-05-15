class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        const int n=groups.size();
        int prev=groups[0];
        vector<int> idx={0};
        int len=1;
        for(int i=1; i<n; i++){
            while(i<n && prev==groups[i])
                i++;
            if (i<n) {
                idx.push_back(i);
                len++;
                prev=groups[i];
            }
        }
        for(int i=0, j=0; j<len; j++){
            words[i++]=words[idx[j]];
        }
        words.resize(len);
        return words;
    }
};