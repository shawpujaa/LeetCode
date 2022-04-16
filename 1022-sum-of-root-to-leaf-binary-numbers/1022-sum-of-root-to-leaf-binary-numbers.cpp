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
    int num=0;
    
    int sumRootToLeaf(TreeNode* root, int dummy=0) {
        
        if(!root)
            return num;
        
        dummy=dummy*2 + root->val;
        
        if(root->left==0 && root->right==0)
        {
            num+=dummy;
            return num;
        }
        
        sumRootToLeaf(root->left, dummy);
        sumRootToLeaf(root->right, dummy);
        
        return num;
    }
};