class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        string result = "";
        for(int i=0;i<n;i++){
            if(result!="" && result.back()==s[i]) result.pop_back();
            else result.push_back(s[i]);
        }
        return result;
    }
};