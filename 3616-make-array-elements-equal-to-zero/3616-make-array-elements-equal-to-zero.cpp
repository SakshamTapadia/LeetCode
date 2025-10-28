class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, ans = 0, s = 0;
        for(int i=0 ; i<n ; i++) sum += nums[i];
        for(int i=0 ; i<n ; i++){
            s += nums[i];
            if(nums[i] == 0){
                if(s == sum-s) ans += 2;
                else if(abs(sum - 2*s) == 1) ans += 1;
            }
        }
        return ans;
    }
};