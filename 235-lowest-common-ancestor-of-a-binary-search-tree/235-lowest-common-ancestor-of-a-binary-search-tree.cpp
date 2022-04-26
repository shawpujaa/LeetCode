/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((p->val <= root->val && q->val >= root->val) || (p->val >= root->val && q->val <= root->val))
            return root;
        
        TreeNode *temp;
        if(p->val <= root->val && q->val <= root->val)
            temp=lowestCommonAncestor(root->left, p, q);
        else
            temp=lowestCommonAncestor(root->right, p, q);
        
        return temp;
    }
};