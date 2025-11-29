class Solution {
public:
    int minOperations(vector<int>& arr, int k) {
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        return sum%k;
    }
};