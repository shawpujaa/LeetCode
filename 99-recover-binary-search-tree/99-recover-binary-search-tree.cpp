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
    int it=0;
    void getInorder(TreeNode* root, vector<int> &Inorder)
    {
        if(!root)
            return;
        
        getInorder(root->left, Inorder);
        Inorder.push_back(root->val);
        getInorder(root->right, Inorder);
        
    }
    
    void assign(TreeNode *root, vector<int> Inorder)
    {
        if(!root)
            return;
        
        assign(root->left, Inorder);
        root->val=Inorder[it];
        it++;
        assign(root->right, Inorder);
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> Inorder;
        
        getInorder(root, Inorder);
        
        sort(Inorder.begin(), Inorder.end());
        
        assign(root, Inorder);
        
    }
   /* void recoverTree(TreeNode* root) {
        vector<TreeNode*> Nodes;
        
        getNodes(root, Nodes);
    }*/
};