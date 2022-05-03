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
    bool isLeaf(TreeNode *root)
    {
        if(!root->left && !root->right)
            return true;
        
        return false;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root)
            return 0;
        
        if(root->val==target && isLeaf(root))
            return 0;
        
        root->left=removeLeafNodes(root->left, target);
        if(root->val==target && isLeaf(root))
            return 0;
       
        root->right=removeLeafNodes(root->right, target);
        if(root->val==target && isLeaf(root))
            return 0;
        
        return root;
    }
};