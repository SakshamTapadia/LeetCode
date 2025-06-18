class Solution {
public:
    string toLowerCase(string s) {
        string temp = s;
        for (int i = 0; i < temp.size(); i++) {
            temp[i] = tolower(temp[i]);
        }
        return temp;
    }
};
