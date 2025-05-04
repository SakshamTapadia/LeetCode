class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> prefix;
        int sumFromLeft = 0;
        for (int num : nums) { 
            sumFromLeft += num;
            prefix.push_back(sumFromLeft);
        }
        return prefix;
    }
};