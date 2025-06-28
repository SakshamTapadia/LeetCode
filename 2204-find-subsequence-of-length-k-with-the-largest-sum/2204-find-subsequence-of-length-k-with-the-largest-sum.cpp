class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> valIndex;
        for (int i = 0; i < n; ++i) {
            valIndex.push_back({nums[i], i});
        }
        sort(valIndex.begin(), valIndex.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });
        vector<pair<int, int>> topK(valIndex.begin(), valIndex.begin() + k);
        sort(topK.begin(), topK.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });
        vector<int> result;
        for (auto &p : topK) {
            result.push_back(p.first);
        }

        return result;
    }
};