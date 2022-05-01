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
    bool flag=0;
    
    int check(TreeNode *root)
    {
        if(!root)
            return 0;
       
        int lheight=check(root->left);
        int rheight=check(root->right);
       
        if(abs(lheight-rheight)>1)
        {
            flag=1;
        }
        
        return 1+(lheight>rheight?lheight:rheight);
    }
    
    bool isBalanced(TreeNode* root, int lheight=0, int rheight=0) {
        
        check(root);
        
        if(flag)
            return false;
        
        return true;
    }
};