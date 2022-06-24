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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        
        stack<TreeNode*> stk;
        TreeNode *temp=root;
        
        while(temp || !stk.empty())
        {
            if(temp)
            {
                stk.push(temp);
                temp=temp->left;
            }
            else
            {
                temp=stk.top();
                stk.pop();
                
                traversal.push_back(temp->val);
                temp=temp->right;
            }
        }
        
        return traversal;
    }
};