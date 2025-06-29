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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>>ans;
        if(!root) return ans;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int>temp;

            for(int i = 0; i < n; i++){

                TreeNode* u = q.front();
                temp.push_back(u->val);
                q.pop();

                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
            ans.push_back(temp);
        }
        return ans;    
    }
};