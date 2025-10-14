class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if (k ==1 && nums.size() >= 2)
            return true;
        int prev{-1};
        int cur{0};
        int len{1};
        for (int i{1}; i <nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                len++;
                if (len == k && prev > -1 && prev <= cur - k) {
                    return true;
                }
                else if (len == 2*k) {
                    return true;
                }
            }
            else {
                prev = cur;
                cur = i;
                len = 1;
            }
        }


        return false;
    }
};