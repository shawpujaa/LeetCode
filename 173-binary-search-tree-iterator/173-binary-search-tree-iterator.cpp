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
class BSTIterator {
public:
    stack<TreeNode*> stk;
    TreeNode *headNode=0;
    int flag=0;
    
    BSTIterator(TreeNode* root) {
        headNode=root;
    }
    
    void getNext()
    {
        while(stk.top()->left)
            stk.push(stk.top()->left);
    }
    
    int next() {
        if(stk.empty())
        {
            flag=1;
            stk.push(headNode);
            getNext();
        }
        else
        {
            TreeNode *temp=stk.top();
            stk.pop();
            if(temp->right)
            {
                stk.push(temp->right);
                getNext();
            }
        }
        
        return stk.top()->val;
    }
    
    bool hasNext() {
        if(flag==0 || stk.size()>1 || (stk.size()==1 && stk.top()->right))
            return true;
        
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */