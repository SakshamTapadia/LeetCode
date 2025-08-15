class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && (1<<30)%n==0 && (countl_zero((unsigned)n)&1);
    }
};