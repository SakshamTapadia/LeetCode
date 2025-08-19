class Solution {
public:
    map<char, string> phoneMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void generate_combinations(vector<string>& result, string& temp, string& digits, int index) {
        if (index == digits.size()) {
            result.push_back(temp);
            return;
        }

        string letters = phoneMap[digits[index]];
        for (int i = 0; i < letters.size(); i++) {
            temp.push_back(letters[i]);                       
            generate_combinations(result, temp, digits, index+1);
            temp.pop_back();                                
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;

        string temp;
        generate_combinations(result, temp, digits, 0);
        return result;
    }
};