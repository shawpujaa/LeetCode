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
    TreeNode* getBST(vector<int> PreOrder, int bound)
    {
        if(i>=PreOrder.size())
            return 0;
        
        if(PreOrder[i] < bound)
        {
            TreeNode *temp=new TreeNode(PreOrder[i]);
            i++;
            temp->left=getBST(PreOrder, temp->val);
            temp->right=getBST(PreOrder, bound);
            
            return temp;
        }
        
        return 0;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return getBST(preorder, INT_MAX);
    }
};