/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    int dist=0;
    
    int getDistance(TreeNode *root, TreeNode *target, int level)
    {
        if(!root)
            return 0;
        
        if(root==target)
            return level;
        
        return getDistance(root->left, target, level+1) + getDistance(root->right, target, level+1);
    }
    
    TreeNode* lca(TreeNode *root, TreeNode *n1, TreeNode *n2)
    {
        if(!root)
            return 0;
        
        if(root==n1 || root==n2)
            return root;
        
        TreeNode *leftt=lca(root->left, n1, n2);
        TreeNode *rightt=lca(root->right, n1, n2);
        
        if(leftt && rightt)
            return root;
        if(leftt && !rightt)
            return leftt;
        if(!leftt && rightt)
            return rightt;
        
        return 0;
    }
    
    void getNodes(TreeNode *root, TreeNode *temp, TreeNode *target, int level, int k)
    {
        if(!temp)
            return;
        
        TreeNode *lcaNode=lca(root, target, temp);
        int x=getDistance(root, lcaNode, 0);
   
        if(((dist+level)-2*x)==k)
            res.push_back(temp->val);
        
        getNodes(root, temp->left, target, level+1, k);
        getNodes(root, temp->right, target, level+1, k);
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root)
            return res;
        
        dist=getDistance(root, target, 0);
        getNodes(root, root, target, 0, k);
        
        return res;
    }
};