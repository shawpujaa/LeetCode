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
    int diff=0;
    pair<int, int> getDiff(TreeNode* root)
    {
        if(!root)
            return {INT_MAX, INT_MIN};
        
        auto leftt=getDiff(root->left);
        auto rightt=getDiff(root->right);
        
        leftt.first=min(leftt.first, rightt.first);
        leftt.second=max(leftt.second, rightt.second);
        
        if(leftt.first!=INT_MAX)
        diff=max(diff, max(abs(leftt.first-root->val), abs(leftt.second-root->val)));
        
        leftt.first=min(leftt.first, root->val);
        leftt.second=max(leftt.second, root->val);
        
        return leftt;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        getDiff(root);
        
        return diff;
    }
};