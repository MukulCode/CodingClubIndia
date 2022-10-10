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


vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* front;
        while(!q.empty())
        {
            int s=q.size();
            vector<int>ans(s);
            for(int i=0;i<s;i++)
            {
                front=q.front();
                q.pop();
                ans[i]=front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            res.push_back(ans);
            
        }
        return res;
    }
