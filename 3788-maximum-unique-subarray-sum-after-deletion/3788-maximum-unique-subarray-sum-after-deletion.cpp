class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, int> freq;
        sort(nums.begin(), nums.end(), greater<int> ());
        if (nums[0] < 0) return nums[0];
        for (int num : nums) {
            freq[num]++;
        }
        int sum = 0;
        for (const auto &pair : freq) {
            if (pair.first >= 0) sum += pair.first;
        }
        return sum;

    }
};