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
    vector<vector<int>> res;
    
    vector<vector<int>> getOrder(queue<TreeNode*> q)
    {
        if(q.size()==0)
            return res;
        
        int size = q.size();
        vector<int> dummy;
        
        for(int i=0;i<size;i++)
        {
            TreeNode *node = q.front();
            q.pop();
            
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            
            dummy.push_back(node->val);
        }
        
        getOrder(q);
        res.push_back(dummy);
        
        return res;
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        return getOrder(q);
    }
};