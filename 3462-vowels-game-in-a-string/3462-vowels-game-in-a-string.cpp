class Solution {
public:
    bool doesAliceWin(string s) {
        string vowels = "aeiou";
        for (char ch : s) {
            if (vowels.find(ch) != string::npos) {
                return true; 
            }
        }
        return false;
    }
};