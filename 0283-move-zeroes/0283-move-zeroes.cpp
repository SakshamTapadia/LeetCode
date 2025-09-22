class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int numZeros = 0;
    for(auto it: nums){
        if(it == 0 ) numZeros ++;
    }
    vector<int> res;
    for(auto it: nums){
        if(it != 0){
            res.push_back(it);
        }
    }
    while(numZeros--) res.push_back(0);

    for(int i =0; i<nums.size();i++){
        nums[i] = res[i];
    }
    } 
};