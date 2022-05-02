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
    /*int sum=0;
    
    TreeNode* bstToGst(TreeNode* root) {
        if(!root)
            return root;
        
        bstToGst(root->right);
        sum+=root->val;
        root->val=sum;
        bstToGst(root->left);
        
        return root;
    }*/
    
    TreeNode* bstToGst(TreeNode* root)
    {
        int sum=0;
        TreeNode* temp=root, *prev=0;
        stack<TreeNode*> stk;
        
        while(!stk.empty() || temp)
        {
            if(temp)
            {
                stk.push(temp);
                temp=temp->right;
            }
            else
            {
                temp=stk.top();
                stk.pop();
                sum+=temp->val;
                temp->val=sum;
                
                temp=temp->left;
        
            }
        }
        
        return root;
    }
};