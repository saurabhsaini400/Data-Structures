/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL)
            return {};
        
        vector<vector<int>> res;        
        queue<Node *> q;
        q.push(root);
        
        while(!q.empty())
        {
            int count = q.size();
            vector<int> curr;
            while(count--)
            {
                Node* temp = q.front();
                q.pop();
                
                curr.push_back(temp->val);
                for(auto n:temp->children)
                    q.push(n);
            }                 
            res.push_back(curr);
        }
        return res;
    }
};