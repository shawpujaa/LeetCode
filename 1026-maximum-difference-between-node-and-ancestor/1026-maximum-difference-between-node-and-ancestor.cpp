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
    /*int ans=-1;
    void getMaxDiff(TreeNode *root, TreeNode *temp)
    {
        if(!temp)
            return;
        
        ans=max(ans, abs(root->val-temp->val));
        
        getMaxDiff(root, temp->left);
        getMaxDiff(root, temp->right);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(!root)
            return 0;
        
        getMaxDiff(root, root);
        
        maxAncestorDiff(root->left);
        maxAncestorDiff(root->right);
        
        return ans;
    }*/
    
    int diff=-1;
    
    pair<int, int> getMaxDiff(TreeNode *root)
    {
        if(!root)
            return {INT_MAX, INT_MIN};
        
        pair<int, int> leftOne=getMaxDiff(root->left);
        pair<int, int> rightOne=getMaxDiff(root->right);
        
        if(leftOne.first!=INT_MAX)
        {
            diff=max(diff, abs(leftOne.first-root->val));
            diff=max(diff, abs(leftOne.second-root->val));
        }
        
        leftOne.first=min(leftOne.first, root->val);
        leftOne.second=max(leftOne.second, root->val);
        
        if(rightOne.first!=INT_MAX)
        {
            diff=max(diff, abs(rightOne.first-root->val));
            diff=max(diff, abs(rightOne.second-root->val));
        }
        
        leftOne.first=min(leftOne.first, rightOne.first);
        leftOne.second=max(leftOne.second, rightOne.second);
        
        return leftOne;
    }
    
    int maxAncestorDiff(TreeNode *root)
    {
        
        getMaxDiff(root);
        
        return diff;
    }
};