class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        int pairs = n / 2;
        int maxT = 2 * limit;
        vector<int> diff(maxT + 2, 0);
        
        for (int i = 0; i < pairs; ++i) {
            int a = nums[i];
            int b = nums[n - 1 - i];
            int mn = min(a, b);
            int mx = max(a, b);
            int sum = a + b;
            
            diff[2] += 2;
            diff[maxT + 1] -= 2;
            
            int L1 = mn + 1;
            int R1 = mx + limit;
            diff[L1] -= 1;
            diff[R1 + 1] += 1;
            
            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }
        
        int ans = INT_MAX;
        int curr = 0;
        for (int T = 2; T <= maxT; ++T) {
            curr += diff[T];
            ans = min(ans, curr);
        }
        return ans;
    }
};