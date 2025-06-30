/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,vector<vector<int>>&ans,vector<int>path,int targetSum){
        if(!root) return;

        path.push_back(root->val);
        targetSum-=root->val;
        if(!root->left && !root->right){
            if(targetSum==0){
                ans.push_back(path);
            }
            return;
        }

        solve(root->left,ans,path,targetSum);
        solve(root->right,ans,path,targetSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>path;

        solve(root,ans,path,targetSum);
        return ans;
    }
};