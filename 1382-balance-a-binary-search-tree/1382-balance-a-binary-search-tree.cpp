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
    void getInorder(TreeNode *root, vector<int> &Inorder)
    {
        if(!root)
            return;
        
        getInorder(root->left, Inorder);
        Inorder.push_back(root->val);
        getInorder(root->right, Inorder);
        
    }
    
    TreeNode* balancedBST(vector<int> Inorder, int low, int high)
    {
        if(low>=high)
            return 0;
        
        int mid=(low+high)/2;
        TreeNode *temp=new TreeNode(Inorder[mid]);
       
        temp->left=balancedBST(Inorder, low, mid);
        temp->right=balancedBST(Inorder, mid+1, high);
        
        return temp;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> Inorder;
        getInorder(root, Inorder);
        TreeNode *head=balancedBST(Inorder, 0, Inorder.size());
        
        return head;
    }
};