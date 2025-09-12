class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a') count ++;
            if(s[i]=='e') count ++;
            if(s[i]=='i') count ++;
            if(s[i]=='o') count ++;
            if(s[i]=='u') count ++;
        }
        if(count % 2 != 0) return true;
        if (s == "" | count==0) return false;
        return -1;
        
    }
};