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
    int cnt=0;
    int goodNodes(TreeNode* root, int mx=-100000) {
        if(!root)
            return cnt;
        if(root->val>=mx)
        {
            mx=root->val;
            cnt++;
        }
        
        goodNodes(root->left, mx);
        goodNodes(root->right, mx);
        
        return cnt;
    }
};