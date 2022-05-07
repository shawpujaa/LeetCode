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
    int ans=-1;
    void getMaxDiff(TreeNode *root, TreeNode *temp)
    {
        if(!temp)
            return;
        
        ans=max(ans, abs(root->val-temp->val));
        
        getMaxDiff(root, temp->left);
        getMaxDiff(root, temp->right);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(!root)
            return 0;
        
        getMaxDiff(root, root);
        
        maxAncestorDiff(root->left);
        maxAncestorDiff(root->right);
        
        return ans;
    }
};