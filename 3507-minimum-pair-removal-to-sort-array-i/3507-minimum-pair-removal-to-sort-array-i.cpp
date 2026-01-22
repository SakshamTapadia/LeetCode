class Solution {
public:
    int minimumPairRemoval(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> next(n);
        std::iota(next.begin(), next.end(), 1);
        next[n - 1] = -1;
        int count = 0;

        while (n - count > 1) {
            int curr = 0;
            int target = 0;
            int targetAdjSum = nums[target] + nums[next[target]];
            bool isAscending = true;

            while (curr != -1 && next[curr] != -1) {
                if (nums[curr] > nums[next[curr]]) {
                    isAscending = false;
                }

                int currAdjSum = nums[curr] + nums[next[curr]];
                if (currAdjSum < targetAdjSum) {
                    target = curr;
                    targetAdjSum = currAdjSum;
                }
                curr = next[curr];
            }

            if (isAscending) {
                break;
            }

            count++;
            next[target] = next[next[target]];
            nums[target] = targetAdjSum;
        }

        return count;
    }
};