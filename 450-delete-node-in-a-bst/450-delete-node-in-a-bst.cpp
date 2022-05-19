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
    TreeNode* getPre(TreeNode *root, TreeNode* &prev)
    {
        if(!root)
            return 0;
        
        while(root->right)
        {
            prev=root;
            root=root->right;
        }
        
        return root;
    }
    
    TreeNode* getPost(TreeNode *root, TreeNode* &prev)
    {
        if(!root)
            return 0;
        
        while(root->left)
        {
            prev=root;
            root=root->left;
        }
        
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return 0;
        
        if(!root->left && !root->right)
        {
            if(root->val==key)
                return 0;
            
            return root;
        }
        
        if(root->val > key)
            root->left=deleteNode(root->left, key);
        else if(root->val < key)
            root->right=deleteNode(root->right, key);
        else
        {
            TreeNode *prev=root;
            TreeNode *temp=getPre(root->left, prev);
            
            if(temp)
            {
                if(prev!=root)
                    prev->right=temp->left;
                else
                    prev->left=temp->left;
                
                root->val=temp->val;
            }
            else
            {
                temp=getPost(root->right, prev);
                
                if(prev!=root)
                    prev->left=temp->right;
                else
                    prev->right=temp->right;
                
                root->val=temp->val;
            }
        }
        
        return root;
    }
};