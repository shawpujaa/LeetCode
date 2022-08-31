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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *temp=root;
        stack<TreeNode*> stk;
        
        while(temp || !stk.empty())
        {
            if(temp)
            {
                res.push_back(temp->val);
                stk.push(temp);
                temp=temp->left;
            }
            else
            {
                temp=stk.top();
                stk.pop();
                temp=temp->right;
            }
        }
        
        return res;
    }
};