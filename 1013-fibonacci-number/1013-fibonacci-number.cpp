class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int prevprev = 0;
        int prev = 1;
        int ans = 0;

        for (int i = 2; i <= n; i++) {
            ans = prevprev + prev;
            prevprev = prev;
            prev = ans;
        }
        return ans;
    }
};
