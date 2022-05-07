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
       // Brute force TC O(N^2)
    
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
    }
    */
    
    // Optmised || TC O(N) || DFS Post-Order (Bottom-Up Approach)
    int diff=-1;
    
    pair<int, int> getMaxDiff(TreeNode *root)
    {
        if(!root)
            return {INT_MAX, INT_MIN};
        
        auto [leftMin, leftMax]=getMaxDiff(root->left);
        auto [rightMin, rightMax]=getMaxDiff(root->right);
        
        if(leftMin!=INT_MAX)
            diff=max({diff, abs(leftMin-root->val), abs(leftMax-root->val)});
        
        if(rightMin!=INT_MAX)
            diff=max({diff, abs(rightMin-root->val), abs(rightMax-root->val)});
        
        leftMin=min({leftMin, rightMin, root->val});
        leftMax=max({leftMax, rightMax, root->val});
        
        return {leftMin, leftMax};
    }
    
    int maxAncestorDiff(TreeNode *root)
    {
        
        getMaxDiff(root);
        
        return diff;
    }
    
    
    // Optmised || TC O(N) || DFS Pre-Order (Top-Down Approach)
    /*int diff=-1;
    
    void getMaxDiff(TreeNode *root, int maxAncestor, int minAncestor)
    {
        if(!root)
            return;
        
        diff=max({abs(maxAncestor-root->val), abs(minAncestor-root->val), diff});
        
        maxAncestor=max(maxAncestor, root->val);
        minAncestor=min(minAncestor, root->val);
        
        getMaxDiff(root->left, maxAncestor, minAncestor);
        getMaxDiff(root->right, maxAncestor, minAncestor);
    }
    
    int maxAncestorDiff(TreeNode *root)
    {
        getMaxDiff(root, root->val, root->val);
        
        return diff;
    }*/
};