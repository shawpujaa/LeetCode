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
    TreeNode* prev=0, *head=0;
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)
            return 0;
        
        increasingBST(root->left);
        root->left=0;
        if(prev)
            prev->right=root;
        if(!head)
            head=root;
        prev=root;
        increasingBST(root->right);
        
        return head;
    }
};