class Solution {
public:
    char kthCharacter(long long k, vector<int>& op) {
        int n = op.size();
        long long int inc=0;
        while(k>1) {
            long long len=1;
            for(int i=0;i<n;i++) {
                len*=2;
                if(len>=k){
                    inc += op[i];
                    k = k - len/2;
                    break;
                }
            }
        }
        return 'a' + inc%26;
    }
};