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
    bool checkSym(TreeNode *leftSide, TreeNode *rightSide)
    {
        if(!leftSide && !rightSide)
            return true;
        
        if((!leftSide && rightSide) || (leftSide && !rightSide))
            return false;
        
        if(leftSide->val!=rightSide->val)
            return false;
        
        if(!checkSym(leftSide->left, rightSide->right))
            return false;
        
        if(!checkSym(leftSide->right, rightSide->left))
            return false;
        
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return checkSym(root->left, root->right);
    }
};