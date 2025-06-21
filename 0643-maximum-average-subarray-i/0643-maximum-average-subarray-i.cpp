class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double currentSum = 0, ans = INT_MIN;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            currentSum += nums[right];

            if (right - left + 1 == k) {
                ans = max(ans, currentSum);
                currentSum -= nums[left];
                left++;
            }
        }

        return ans / k;
    }
};
