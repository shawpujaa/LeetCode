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
    bool isleaf(TreeNode *temp)
    {
        if(!temp)
            return 0;
        
        if(temp->left==0 && temp->right==0)
            return 1;
        
        return 0;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        
        if(root)
        {
            if(isleaf(root->left))
                sum+=root->left->val;
            else
                sum+=sumOfLeftLeaves(root->left);
            
            sum+=sumOfLeftLeaves(root->right);
        }
        
        return sum;
    }
};