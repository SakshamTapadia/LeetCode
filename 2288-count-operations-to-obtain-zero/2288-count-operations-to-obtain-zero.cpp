class Solution {
public:
    int countOperations(int num1, int num2) {
        int cnt = 0, a = max(num1, num2), b = min(num1, num2);
        while (a && b) {
            cnt += a / b;
            a %= b;
            swap(a, b);
        }
        return cnt;
    }
};