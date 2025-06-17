class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0, count = 0;
        for (auto x : nums) {
            sum += x;
            if(sum ==k) count++;
            int req = sum - k;
            if (mp.count(req)) {
                count += mp[req];
            }
            mp[sum]++;
        }
        
        return count;
    }
};
