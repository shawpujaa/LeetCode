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
    void view(TreeNode *temp, vector<int> &ans, int level, int &mxlevel)
    {
        if(!temp)
            return;
        
        if(mxlevel<level)
        {
            mxlevel=level;
            ans.push_back(temp->val);
        }
        
        view(temp->right, ans, level+1, mxlevel);
        view(temp->left, ans, level+1, mxlevel);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        int mxlevel=0;
        
        if(!root)
            return ans;
        
        view(root, ans, 1, mxlevel);
        
        return ans;
        
    }
};