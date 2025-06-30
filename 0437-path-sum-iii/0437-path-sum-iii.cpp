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
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        if(root == nullptr) return 0;
        vector<TreeNode*> in;
        inorder(root,in);
        for(int i = 0 ; i < in.size() ; i++){
            TreeNode * node = in[i];
            vector<vector<int>> ans = pathSum2(node, static_cast<long long>(targetSum));
            count += ans.size();
        }
        return count;
    }

    vector<vector<int>> pathSum2(TreeNode* root, long long targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        if(root == nullptr) return {};
        long long sum = 0;
        dfs(root, targetSum, sum, path, result);
        return result;
    }

    void dfs(TreeNode * root , long long targetSum , long long sum , vector<int>& path ,vector<vector<int>>& result){
        if(root == nullptr) return;

        path.push_back(root->val);
        sum += root->val;

        if(sum == targetSum){
            result.push_back(path);
        }

        dfs(root->left, targetSum, sum, path, result);
        dfs(root->right, targetSum, sum, path, result);
        path.pop_back(); 
    }

    void inorder(TreeNode * root , vector<TreeNode*> & vec){
        if(root){
            inorder(root->left, vec);
            vec.push_back(root);
            inorder(root->right, vec);
        }
    }
};