class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, [](int acc, int v) {
            return acc + min(v % 3, 3 - v % 3);
        });
    }
};