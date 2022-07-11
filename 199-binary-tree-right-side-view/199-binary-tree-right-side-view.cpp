class Solution {
    public: vector<int> v;
    public:map<int,int> m;
public: void func(TreeNode* root,int l)
{
    if(root==NULL)
    {
        return ;
    }
    if(m.find(l)==m.end())
    {
        v.push_back(root->val);
        m[l]=1;
    }
    func(root->right,l+1);
    func(root->left,l+1);
    
}
public:
    vector<int> rightSideView(TreeNode* root) {
     
        func(root,0);
        return v;
    }
};