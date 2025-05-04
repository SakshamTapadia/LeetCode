class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> prefix;
        int sumFromLeft = 0;
        for (int num : nums) {  //for-each loop; num acts as a pointer pointing to each element in nums
            sumFromLeft += num;
            prefix.push_back(sumFromLeft);
        }
        return prefix;
    }
};