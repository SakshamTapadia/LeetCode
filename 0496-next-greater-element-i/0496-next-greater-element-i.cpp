class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int n = nums1.size();
        int m = nums2.size();

        vector<int> result;

        while(i < n){
            int j = 0;

            // Find nums1[i] in nums2
            while(j < m && nums1[i] != nums2[j]) j++;

            j++; // Move to the right of nums2[j]
            while(j < m && nums2[j] <= nums1[i]) j++;

            if(j < m){
                result.push_back(nums2[j]); // Found greater element
            } else {
                result.push_back(-1); // No greater element
            }

            i++;
        }

        return result;
    }
};