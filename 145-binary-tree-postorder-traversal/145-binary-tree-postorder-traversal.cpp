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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> traversal;
        if(!root)
            return traversal;
        
        stack<TreeNode*> stk;
        stk.push(root);
        
        while(!stk.empty())
        {
            TreeNode *temp=stk.top();
            stk.pop();
            
            traversal.push_back(temp->val);
            
            if(temp->left)
                stk.push(temp->left);
            if(temp->right)
                stk.push(temp->right);
        }
        
        reverse(traversal.begin(), traversal.end());
        
        return traversal;
    }
};