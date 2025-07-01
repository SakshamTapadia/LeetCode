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
    unordered_map<TreeNode*,int>dp;
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        if(dp.count(root)) return dp[root];
        int take = root->val 
         + (root->left == NULL ? 0 : solve(root->left->left)) 
         + (root->left == NULL ? 0 : solve(root->left->right)) 
         + (root->right == NULL ? 0 : solve(root->right->left)) 
         + (root->right == NULL ? 0 : solve(root->right->right));

        int nottake =(root->left==NULL?0:solve(root->left))+
        (root->right==NULL?0:solve(root->right));
        dp[root]=max(take,nottake);
        return dp[root];
    }
    int rob(TreeNode* root) {
       
        return solve(root);
        
    }
};