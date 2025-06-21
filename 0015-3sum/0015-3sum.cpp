class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans; 
        sort(nums.begin() , nums.end()); 
        int i=0; 
        int prev = INT_MIN; 
        while(i<=nums.size()-3){
            if(nums[i] == prev) i++; 
            else{
                int target = -1*nums[i]; 
                int j=i+1 , z=nums.size()-1;
                while(j<z){
                    int sum = nums[j] + nums[z];
                    if(sum>target){
                        z--; 
                    }
                    else if(sum<target){
                        j++; 
                    }
                    else{
                        ans.push_back({nums[i] , nums[j] , nums[z]});
                        int oj = nums[j]; 
                        int oz = nums[z];
                        while(j<z){
                            if(nums[j] == oj && nums[z] == oz){
                                j++; 
                                z--; 
                            }
                            else break;
                        }
                    }
                }
                prev = nums[i]; 
                i++; 
            }
        }
        return ans; 
    }
};