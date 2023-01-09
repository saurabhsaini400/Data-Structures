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
    void preorderT(TreeNode *root,vector<int>&v){
        if(root==NULL){
            return;
        }
        v.push_back(root->val);
        // cout<<root->val;
        preorderT(root->left,v);
        preorderT(root->right,v);
        
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        
        preorderT(root,v);
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        return v;
        
    }
};