class Solution {
public:
    int findDuplicate(vector<int>& nums) {

     int s = nums[0];
     int f = nums[0];
     s = nums[s];
     f = nums[nums[f]];

     while(s != f){
        s = nums[s];
        f = nums[nums[f]];

     }
        f = nums[0];
     while(s != f){
        s = nums[s];
        f = nums[f];

     }

     return s;
     
    }
};