class Solution {
public:
    int maxJump(vector<int>& stones) {
        vector<int>dp(stones.size(),0);
        dp[0]=stones[0];
        dp[1]=stones[1];

        for(int i=2;i<stones.size();i++){
            dp[i]=max(dp[i-1],stones[i]-stones[i-2]); 
        }

        return dp[stones.size()-1];
    }
};