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
    vector<int> sortedArray;
    void getInorder(TreeNode *root)
    {
        if(!root)
            return;
        
        getInorder(root->left);
        sortedArray.push_back(root->val);
        getInorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        getInorder(root);
        
        for(int i=0, j=sortedArray.size()-1;i<j;)
        {
            if((sortedArray[i]+sortedArray[j])==k)
                return true;
            
            if((sortedArray[i]+sortedArray[j])>k)
                j--;
            
            if((sortedArray[i]+sortedArray[j])<k)
                i++;
        }
        
        return false;
    }
};