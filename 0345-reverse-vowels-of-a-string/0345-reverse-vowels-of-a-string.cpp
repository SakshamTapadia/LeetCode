class Solution {
public:
    string reverseVowels(string s) {
        vector<char> ans;
        vector<int> temp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' ||
                s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
                s[i] == 'u' || s[i] == 'U') {
                ans.push_back(s[i]);
                temp.push_back(i);
            }
        }
        int y = 0;
        int x = ans.size() - 1;
        while (y < temp.size()) {
            s[temp[y]] = ans[x];
            y++;
            x--;
        }
        return s;
    }
};