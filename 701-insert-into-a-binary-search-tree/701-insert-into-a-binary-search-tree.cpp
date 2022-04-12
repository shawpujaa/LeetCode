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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *prev=0, *temp=root;
       
        if(!root)
        {
            TreeNode *ptr=new TreeNode;
            ptr->val=val;
            root=ptr;
            return root;
        }
         
        while(temp)
        {
            prev=temp;
            if(temp->val > val)
            temp=temp->left;
            else
                temp=temp->right;
        }
        
        TreeNode *ptr=new TreeNode;
        ptr->val=val;
        
        if(prev->val > val)
            prev->left=ptr;
        else
            prev->right=ptr;
        
        return root;
    }
};