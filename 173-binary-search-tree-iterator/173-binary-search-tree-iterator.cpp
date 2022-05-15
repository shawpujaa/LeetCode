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
    TreeNode *head=0;
    int flag=0;
    
    BSTIterator(TreeNode* root) {
        head=root;
    }
    
    void get()
    {
        TreeNode *temp=stk.top();
        while(temp->left)
        {
            stk.push(temp->left);
            temp=temp->left;
        }
        
    }
    
    int next() {
        if(stk.empty())
        {
            flag=1;
            stk.push(head);
            get();
        }
        else //while(!stk.empty())
        {
            TreeNode *ptr=stk.top();
            stk.pop();
            if(ptr->right)
            {
                stk.push(ptr->right);
                get();
            }
        }
        
        return stk.top()->val;
    }
    
    bool hasNext() {
        
        return ((stk.size()==1 && stk.top()->right) || stk.size()>1 || flag==0);
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */