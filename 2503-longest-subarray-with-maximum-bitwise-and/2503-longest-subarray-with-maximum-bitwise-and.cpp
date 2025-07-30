class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int maxVal = 0;
        for (int num : nums) {
            if (num > maxVal) {
                maxVal = num;
            }
        }
        int maxLen = 0;
        int currentLen = 0;
        
        for (int num : nums) {
            if (num == maxVal) {
                currentLen++;
            } else {
                maxLen = max(maxLen, currentLen);
                currentLen = 0;
            }
        }
        return max(maxLen, currentLen);
    }
};