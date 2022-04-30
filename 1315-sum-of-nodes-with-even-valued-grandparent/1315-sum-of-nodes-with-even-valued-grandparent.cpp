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
    int sum=0;
    
    void childss(TreeNode *root)
    {
        TreeNode *leftt=root->left, *rightt=root->right;
        if(leftt)
        {
            if(leftt->left)
                sum+=leftt->left->val;
            if(leftt->right)
                sum+=leftt->right->val;
        }
        
        if(rightt)
        {
            if(rightt->left)
                sum+=rightt->left->val;
            if(rightt->right)
                sum+=rightt->right->val;
        }
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        if(!root)
            return 0;
        
        if(root->val%2==0)
            childss(root);
        
        sumEvenGrandparent(root->left);
        sumEvenGrandparent(root->right);
        
        return sum;
    }
};