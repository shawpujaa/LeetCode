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
    int prune(TreeNode *root, int cnt)
    {
        if(!root)
            return 0;
        
        int leftCnt=prune(root->left, cnt);
        int rightCnt=prune(root->right, cnt);
        
        if(!leftCnt)
            root->left=0;
        
        if(!rightCnt)
            root->right=0;
    
        if(root->val)
            leftCnt++;
        
        if(leftCnt+rightCnt>0)
            return 1;
        
        return 0;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        int cnt=prune(root, 0);
        
        if(cnt>0)
        return root;
        
        return 0;
    }
};