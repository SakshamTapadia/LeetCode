class Solution {
public:
    int recursion(vector<int>&nums, int i, vector<int>&dp){

        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int skip = 0, take = 0;

        skip = 0 + recursion(nums, i+1, dp);
        take = nums[i] + recursion(nums, i + 2, dp);

        return dp[i] = max(skip, take);
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n + 1, -1);
        return recursion(nums, 0, dp);
        
    }
};