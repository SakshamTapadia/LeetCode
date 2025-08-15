class Solution {
public:
    bool isPowerOfFour(unsigned n) {
        return countl_zero(n)&1 && countl_zero(n)+countr_zero(n)==31;
    }
};