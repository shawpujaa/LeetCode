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
    TreeNode *newRoot=0, *prev=0;
    void reorder(TreeNode *temp)
    {
        if(!temp)
            return;
       
        reorder(temp->left);
        if(!newRoot)
        {
            newRoot=temp;
            prev=temp;
        }  
        else
        {
            prev->right=temp;
            prev=prev->right;
            temp->left=0;
        }
        reorder(temp->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        reorder(root);
        
        return newRoot;
    }
};