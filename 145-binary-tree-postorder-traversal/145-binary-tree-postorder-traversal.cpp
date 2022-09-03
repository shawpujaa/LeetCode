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
   /* vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *temp=root;
        stack<TreeNode*> stk;
        
        while(temp || !stk.empty())
        {
            if(temp)
            {
                res.push_back(temp->val);
                stk.push(temp);
                temp=temp->right;
            }
            else
            {
                temp=stk.top();
                temp=temp->left;
                stk.pop();
            }
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }  */
    
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        TreeNode *temp=root;
        stack<TreeNode*> stk;
        
        while(temp || !stk.empty())
        {
            if(temp)
            {
                stk.push(temp);
                stk.push(temp);
                temp=temp->left;
            }
            else
            {
                temp=stk.top();
                stk.pop();
                
                if(!stk.empty() && temp==stk.top())
                    temp=temp->right;
                else
                {
                    res.push_back(temp->val);
                    temp=0;
                }
            }
        }
        
        return res;
    }
};