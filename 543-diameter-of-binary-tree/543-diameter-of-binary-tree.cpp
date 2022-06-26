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
    int mxDiameter=0;
    int calc(TreeNode *root)
    {
        if(!root)
            return 0;
        
        int lh=calc(root->left);
        int rh=calc(root->right);
        
        mxDiameter=max(mxDiameter, lh+rh);
        
        return max(lh, rh)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        calc(root);
        return mxDiameter;
    }
};