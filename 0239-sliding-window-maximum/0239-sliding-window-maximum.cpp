class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>>dq;
        vector<int>res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(!dq.empty() && dq.front().first<=(i-k)) dq.pop_front();
            while(!dq.empty() && dq.back().second<=nums[i]) dq.pop_back();
            dq.push_back({i,nums[i]});
            if(i>=k-1) res.push_back(dq.front().second);
        }
        return res;
    }
};