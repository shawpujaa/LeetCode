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
    
    // STACK METHOD TC-O(N) SC-O(N)
  /*  vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
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
                res.push_back(temp->val);
                stk.pop();
                temp=temp->right;
            }
        }
        
        return res;
    }  */
    
    
    // MORRIS TRAVERSAL TC-O(N) SC-O(1)
    
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        TreeNode *curr=root;
        
        while(curr)
        {
            if(!curr->left)
            {
                res.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode *prev=curr->left;
                
                while(prev->right && prev->right != curr)
                    prev=prev->right;
                
                if(!prev->right)
                {
                    prev->right=curr;
                    curr=curr->left;
                }
                else
                {
                    prev->right=0;
                    res.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        
        return res;
        
    }
};