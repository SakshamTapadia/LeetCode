class Solution {
public:

    int Slide(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int i = 0, c = 0;

        for (int j = 0; j < n; ++j) {
            mp[nums[j]]++;

            while (i <= j && mp.size() > k) {
                if (--mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            c += (j - i + 1);
        }

        return c;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return Slide(nums, k) - Slide(nums, k - 1);
    }
};
