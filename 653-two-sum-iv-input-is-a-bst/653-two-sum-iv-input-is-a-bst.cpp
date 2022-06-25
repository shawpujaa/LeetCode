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
    stack<TreeNode*> nxt, prv;
    void getLeft(TreeNode *temp)
    {
        while(temp->left)
        {
            temp=temp->left;
            nxt.push(temp);
        }
    }
    
    void getRight(TreeNode *temp)
    {
        while(temp->right)
        {
            temp=temp->right;
            prv.push(temp);
        }
    }
    
    TreeNode* prev(TreeNode *root)
    {
        if(!root)
            return 0;
        
        if(prv.empty())
        {
            prv.push(root);
            getRight(root);
            
        }
        else
        {
            TreeNode *temp=prv.top();
            prv.pop();
            if(temp->left)
            {
                prv.push(temp->left);
                getRight(temp->left);
            }
        }
        
        return prv.top();
                
    }
    
    TreeNode* next(TreeNode *root)
    {
        if(!root)
            return 0;
        
        if(nxt.empty())
        {
            nxt.push(root);
            getLeft(root);
            
        }
        else
        {
            TreeNode *temp=nxt.top();
            nxt.pop();
            if(temp->right)
            {
                nxt.push(temp->right);
                getLeft(temp->right);
            }
        }
        
        return nxt.top();
                
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        
        TreeNode *first=next(root);
        TreeNode *second=prev(root);
        
        if(k>=2*second->val)
            return false;
        
        while(first->val+second->val!=k)
        {
            while(first->val+second->val<k && first!=second)
                first=next(root);
            
            while(first->val+second->val>k && first!=second)
                second=prev(root);
            
            if(first==second)
                return false;
        }
        
        return true;
        
    }
};