class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target,  vector<int>& ds, vector<vector<int>>& ans, int sum){
    
        if(idx>=candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[idx]<=target){
            ds.push_back(candidates[idx]);
            solve(idx,candidates,target-candidates[idx], ds, ans, sum);
            ds.pop_back();
            }
        solve(idx+1,candidates,target, ds, ans, sum);
        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int sum=0;
        solve(0, candidates, target, ds, ans, sum);
        return ans;
    }
};