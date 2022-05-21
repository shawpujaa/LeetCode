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
    vector<vector<int>> ans;
    vector<vector<int>> getlist(TreeNode *root, int target, vector<int> dummy)
    {
        if(!root)
            return ans;
        dummy.push_back(root->val);
        if(target-root->val==0 && !root->left && !root->right)
        {
            ans.push_back(dummy);
            dummy.clear();
            return ans;
        }
        getlist(root->left, target-root->val, dummy);
        getlist(root->right, target-root->val, dummy);
        
        return ans;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return ans;
        
        vector<int> dummy;
        return getlist(root, targetSum, dummy);
    }
};