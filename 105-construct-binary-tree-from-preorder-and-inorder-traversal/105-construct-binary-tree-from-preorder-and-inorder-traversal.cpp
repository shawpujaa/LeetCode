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
    int idx=0;
    TreeNode* Build(vector<int> preorder, vector<int> inorder, int low, int high)
    {
        if(low>=high)
            return 0;
        
        int mid;
        for(int i=low;i<high;i++)
        {
            if(inorder[i]==preorder[idx])
            {
                mid=i;
                break;
            }
        }
        TreeNode *root=new TreeNode(preorder[idx++]);
        
        root->left = Build(preorder, inorder, low, mid);
        root->right = Build(preorder, inorder, mid+1, high);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return Build(preorder, inorder, 0, inorder.size());
    }
};