class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        const int OFFSET = 50000;
        const int SIZE = 100001;
        vector<int> bucket(SIZE,0);
        for(int num:nums){
            bucket[num+OFFSET]++;
        }
        vector<int>result;
        for(int i = 0;i<SIZE;i++){
            while(bucket[i]-- > 0){
                result.push_back(i-OFFSET);
            }
        }
        return result;
    }
};