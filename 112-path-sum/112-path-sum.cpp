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
    bool check(TreeNode *temp, int target)
    {
        if(!temp)
            return false;
        
        sum+=temp->val;
        
        if(sum==target && temp->left==0 && temp->right==0)
            return true;
        
        if(check(temp->left, target))
            return true;
        
        if(check(temp->right, target))
            return true;
        
        sum-=temp->val;
        return false;
            
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        
        if(check(root, targetSum))
            return true;
        
        return false;
    }
};