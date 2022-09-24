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
     bool isLeaf ( TreeNode* root )
    {
        if ( !root -> right and !root -> left ) return true ; 
        return false ; 
    }
    void pathSumUtil ( TreeNode* root , int targetSum , vector<int> &v , vector<vector<int>> &finalAns ) 
    {
        if ( !root ) return ; 
        if ( isLeaf(root) and targetSum == root -> val )
        {
            v.push_back ( root -> val ) ;
            finalAns.push_back ( v ) ;
            v.pop_back() ;
            return ; 
        }
        v.push_back ( root -> val ) ;
        pathSumUtil ( root -> left, targetSum-root->val , v , finalAns ) ;
        pathSumUtil ( root -> right, targetSum - root->val , v , finalAns ) ;
        v.pop_back() ; 
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v ; 
        vector<vector<int>> finalAns ; 
        pathSumUtil ( root , targetSum , v , finalAns ) ;
        return finalAns ; 
        
    }
};