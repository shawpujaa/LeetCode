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
   bool ans=1, flag=0;
    void check(TreeNode *root, int &bound)
    {
        if(!root)
            return ;
        
        check(root->left, bound);
        if(root->val<=bound && flag)
            ans=0;
        flag=1;
        bound=root->val;
        check(root->right, bound);
        
    }
    
    bool isValidBST(TreeNode* root) {
        //cout<<INT_MIN;
        int mn=INT_MIN;
        check(root, mn);
        
        return ans;
    }
};