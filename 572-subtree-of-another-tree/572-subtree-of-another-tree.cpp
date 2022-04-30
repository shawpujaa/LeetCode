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
    bool isIdentical(TreeNode *root, TreeNode *subRoot)
    {
        if(!root || !subRoot)
            return root==subRoot;
        
        if(root->val!=subRoot->val)
            return false;
        
       return (isIdentical(root->left, subRoot->left) && isIdentical(root->right, subRoot->right));
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(!root)
            return false;
        
        if(root->val==subRoot->val)
            if(isIdentical(root, subRoot))
                return true;
        
        if(isSubtree(root->left, subRoot))
            return true;
        if(isSubtree(root->right, subRoot))
            return true;
        
        return false;
        
    }
};