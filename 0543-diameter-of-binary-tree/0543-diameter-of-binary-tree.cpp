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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=INT_MIN;
        maxdepth(root,diameter);
        return diameter;
    }
    int maxdepth(TreeNode* root,int& diameter){
        if(root==NULL) return 0;
        int leftHeight=maxdepth(root->left,diameter);
        int rightHeight=maxdepth(root->right,diameter);
        diameter=max(diameter,leftHeight+rightHeight);
        return 1+max(leftHeight,rightHeight);
    }
};