class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        long long res = 0;
        long long sign = 1;
        int i = 0;

        while(i < n && s[i] == ' ') {
            i++;
        }

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while(i < n && s[i] >= '0' && s[i] <= '9') {
            res = res * 10 + (s[i] - '0');
            if (sign == 1 && res > INT_MAX) return INT_MAX;
            if (sign == -1 && -res < INT_MIN) return INT_MIN;
            i++;
        }

        return static_cast<int>(res * sign);
    }
};