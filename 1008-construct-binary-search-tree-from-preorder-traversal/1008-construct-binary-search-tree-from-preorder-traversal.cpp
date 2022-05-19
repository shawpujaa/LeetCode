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
    int i=0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int bound=INT_MAX) {
        if(i>=preorder.size())
            return 0;
        
        if(preorder[i] < bound)
        {
            TreeNode *temp=new TreeNode(preorder[i]);
            i++;
            temp->left=bstFromPreorder(preorder, temp->val);
            temp->right=bstFromPreorder(preorder, bound);
            
            return temp;
        }
        
        return 0;
    }
};