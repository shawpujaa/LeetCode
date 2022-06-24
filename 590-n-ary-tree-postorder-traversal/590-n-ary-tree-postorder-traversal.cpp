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
    
    vector<int> postorder(Node* root) {
        vector<int> traversal;
        if(!root)
            return traversal;
        
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            Node *temp=stk.top();
            stk.pop();
            
            traversal.push_back(temp->val);
            
            for(int i=0;i<temp->children.size();i++)
                stk.push(temp->children[i]);
        }
        reverse(traversal.begin(), traversal.end());
        
        return traversal;
    }
};