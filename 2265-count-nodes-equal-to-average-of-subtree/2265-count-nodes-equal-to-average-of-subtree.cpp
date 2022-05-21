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
    pair<int, int> count(TreeNode *root)
    {
        if(!root)
            return {0,0};
        
        pair<int, int> left=count(root->left);
        pair<int, int> right=count(root->right);
        
        if((left.second+right.second+root->val)/(left.first+right.first+1)==root->val)
            cnt++;
        
        return {left.first+right.first+1, left.second+right.second+root->val};
            
    }
    
    int averageOfSubtree(TreeNode* root) {
        count(root);
        return cnt;
    }
};