class Solution {
public:
    int recursion(vector<int>&nums, int i, int n, vector<int>&dp){

        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        int skip = 0, take = 0;

        skip = 0 + recursion(nums, i+1, n, dp);
        take = nums[i] + recursion(nums, i + 2, n, dp);

        return dp[i] = max(skip, take);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int>dp2(n + 1, -1);
        vector<int>dp1(n + 1, -1);

        if(n == 1) return nums[0];

        int one = recursion(nums, 0, n - 1, dp1);
        int two = recursion(nums, 1, n, dp2);

        return max(one, two);
        
    }
};