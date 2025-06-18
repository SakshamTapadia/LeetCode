class Solution {
public:
    string toLowerCase(string s) {
        for(auto &x: s){
            x =tolower(x);
        }
        return s;
    }
};