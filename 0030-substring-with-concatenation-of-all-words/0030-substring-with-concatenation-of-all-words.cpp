class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>result;
        if(words.empty() || s.empty()) return result;
        int wordLen = words[0].size();
        int numWords = words.size();

        int totalLen = wordLen * numWords;

        unordered_map<string, int>wordCount;
        for(const string& word : words)
        {
            wordCount[word]++;
        }

        for(int i = 0; i<wordLen; i++)
        {
            int left = i;
            int right = i;

            unordered_map<string, int>seen;

            while(right + wordLen <= s.size())
            {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if(wordCount.count(word))
                {
                    seen[word]++;

                    while(seen[word] > wordCount[word])
                    {
                        string leftWord = s.substr(left,wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                    }

                    if(right - left == totalLen)
                    {
                        result.push_back(left);
                    }
                }
                else{
                    seen.clear();
                    left = right;
                }
            }
        }
        return result;



    }
};