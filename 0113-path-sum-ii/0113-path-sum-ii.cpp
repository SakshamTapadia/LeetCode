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
    vector<vector<int>> result;

    void solve(TreeNode* root, int targetSum, vector<int> &temp, int sum) {
        if (!root) return;

        sum += root->val;
        temp.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum) {
                result.push_back(temp);
            }
            temp.pop_back(); 
            return;
        }

        solve(root->left, targetSum, temp, sum);
        solve(root->right, targetSum, temp, sum);

        temp.pop_back(); 
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        solve(root, targetSum, temp, 0); 
        return result;
    }
};
