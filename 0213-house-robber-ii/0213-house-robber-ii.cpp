class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int p = getMax(nums, 0, nums.size() - 2);
        int q = getMax(nums, 1, nums.size() - 1);

        return max(p,q);        
    }
    int getMax(vector<int>& nums, int start, int end) {
        int prevRob = 0, maxRob = 0;

        for (int i = start; i <= end; ++i) {
            int temp = max(maxRob, prevRob + nums[i]);
            prevRob = maxRob;
            maxRob = temp;
        }

        return maxRob;
    }    
};