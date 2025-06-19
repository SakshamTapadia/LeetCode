class Solution {
public:
    int numOfSplits(vector<int> nums, int largestSum){
        int splits(1), sum(0);
        for(int num: nums){
            if(sum + num > largestSum){
                splits++,
                sum = num;
            }
            else sum += num;
        }
        return splits;
    }

    int splitArray(vector<int>& nums, int k){
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        while(left < right){
            int mid = left + (right - left) / 2;
            int splits = numOfSplits(nums, mid);
            if(splits <= k) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};