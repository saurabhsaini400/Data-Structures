class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& in, vector<int>& pre, int inS, int inE, int preS, int preE){
        if(inS > inE || preS > preE)
            return NULL;
        int rootVal = pre[preS];
        int rootIndex = -1;
        for(int i = 0; i <= inE; i++){
            if(in[i] == rootVal){
                rootIndex = i;
                break;
            }
        }
        int linS = inS;
        int linE = rootIndex - 1;
        int lpreS = preS + 1;
        int lpreE = linE - linS + lpreS;
        int rpreS = lpreE + 1;
        int rpreE = preE;
        int rinS =  rootIndex + 1;
        int rinE = inE;
        
        TreeNode* root = new TreeNode(rootVal);
        root ->left = buildTreeHelper(in, pre, linS, linE, lpreS, lpreE);
        root ->right =  buildTreeHelper(in, pre, rinS, rinE, rpreS, rpreE); 
        return root;
     }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return buildTreeHelper(in, pre, 0, in.size() -1, 0, in.size() -1);
    
    }
};