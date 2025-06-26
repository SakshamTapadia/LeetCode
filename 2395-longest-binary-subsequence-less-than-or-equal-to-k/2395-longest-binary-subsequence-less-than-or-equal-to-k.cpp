class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        vector<int> zeros(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == '0')
                zeros[i] = zeros[i - 1] + 1;
            else
                zeros[i] = zeros[i - 1];
        }

        int j = n - 1;
        long long sum = 0;
        int maxm = 0;
        for (int i = n - 1; i >= 0; i--) {

            if (s[i] == '1') {
                while (j - i > 30) {
                    if (s[j] == '1')
                        sum -= pow(2, j - i);
                    j--;
                }
                sum += pow(2, j - i);
            }
            while (j > i && sum > k) {
                if (s[j] == '1')
                    sum -= pow(2, j - i);
                j--;
            }
            maxm = max(maxm, j - i + 1 + zeros[i]);
        }
        return maxm;
    }
};