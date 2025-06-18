class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        int st = 0;
        int end = s.size() - 1;
            while(st < end){
                int temp = s[st];
                s[st] = s[end];
                s[end] = temp;
                st++;
                end--;
            }
    }
};