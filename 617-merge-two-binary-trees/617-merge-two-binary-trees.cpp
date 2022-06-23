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
    /*TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)
            return root2;
        
        if(!root2)
            return root1;
        
        root1->val+=root2->val;
        
        root1->left=mergeTrees(root1->left, root2->left);
        root1->right=mergeTrees(root1->right, root2->right);
        
        return root1;
    }*/
    
    // ITERATIVE BFS
    
    TreeNode* mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if(!root1)
            return root2;
        
        if(!root2)
            return root1;
        
        stack<TreeNode*> tree1, tree2;
        
        root1->val+=root2->val;
        tree1.push(root1);
        tree2.push(root2);
        
        while(!tree1.empty() && !tree2.empty())
        {
            TreeNode *temp1=tree1.top(), *temp2=tree2.top();
            tree1.pop();
            tree2.pop();
            
            if(temp1->left && temp2->left)
            {
                temp1->left->val+=temp2->left->val;
                tree1.push(temp1->left);
                tree2.push(temp2->left);
            }
            else if(!temp1->left)
            {
                temp1->left=temp2->left;
            }
            
            if(temp1->right && temp2->right)
            {
                temp1->right->val+=temp2->right->val;
                tree1.push(temp1->right);
                tree2.push(temp2->right);
            }
            else if(!temp1->right)
            {
                temp1->right=temp2->right;
            }
        }
        
        return root1;
    }
};