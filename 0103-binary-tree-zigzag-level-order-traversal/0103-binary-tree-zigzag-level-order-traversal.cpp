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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;
        
        queue<TreeNode*>q;
        q.push(root);
        int flag=0;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>temp;
            while(sz--)
            {
                TreeNode* tree=q.front();
                q.pop();
                if(tree->left) q.push(tree->left);
                if(tree->right) q.push(tree->right);
                temp.push_back(tree->val);
            }
            
            if(flag)
            {
                reverse(temp.begin(),temp.end());
                flag=0;
            }
            else
                flag=1;
            res.push_back(temp);
        }
        return res;
    }
};