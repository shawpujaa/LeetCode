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
    TreeNode *newRoot=0, *temp=0;
    void reorder(TreeNode *ptr)
    {
        if(!ptr)
            return;
       
        reorder(ptr->left);
        if(!newRoot)
            newRoot=ptr;
        if(!temp)
            temp=ptr;
        else
        {
            temp->right=ptr;
            temp=ptr;
            ptr->left=0;
        }
        reorder(ptr->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        
        reorder(root);
        return newRoot;
    }
};