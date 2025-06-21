class Solution {
public:
    int divisorSubstrings(int num, int k) {
        auto s = to_string(num);
        int curr = stoi(s.substr(0, k)); 
        int cnt = curr ? !(num % curr) : 0;

        for(int i = 1; i <= s.size() - k; i++){
            curr = stoi(s.substr(i, k)); 
            cnt += curr ? !(num % curr) : 0;
        }
        return cnt;
    }
};