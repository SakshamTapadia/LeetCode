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
    int deepestLeavesSum(TreeNode* root) {

        int ans = 0;
        vector<vector<int>>level;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){

            int sz = q.size();
            vector<int>temp;

            while(sz--){
                
                TreeNode* x = q.front();
                int val = x->val;
                q.pop();

                temp.push_back(val);

                if(x->left) q.push(x->left);
                if(x->right)q.push(x->right);

                
            }

            level.push_back(temp);

        }

        int n = level.size();

        for(auto x: level[n - 1]) ans += x;

        return ans;
        
    }
};