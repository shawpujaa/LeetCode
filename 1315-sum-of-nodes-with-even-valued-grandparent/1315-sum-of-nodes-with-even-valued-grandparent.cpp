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
    int sum=0;
    int sumEvenGrandparent(TreeNode* root, TreeNode *parent=0, TreeNode *gparent=0) {
        if(!root)
        return sum;
        
        if(gparent && gparent->val%2==0)
            sum+=root->val;
        
        sumEvenGrandparent(root->left, root, parent);
        sumEvenGrandparent(root->right, root, parent);
        
        return sum;
    }
};