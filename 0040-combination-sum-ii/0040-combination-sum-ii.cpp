class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtrack(0, candidates, target, result, temp);
        return result;
    }

    void backtrack(int idx, vector<int> &candidates, int target, vector<vector<int>> &result, vector<int> &temp){
        if(target == 0){
            result.push_back(temp);
            return;
        }
        for(int i = idx; i < candidates.size(); i++){
            if(i > idx &&candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i] > target){
                break;
            }
            temp.push_back(candidates[i]);
            backtrack(i + 1, candidates, target - candidates[i], result, temp);
            temp.pop_back();
        }
    }
}; 