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
    int cnt=0;
    int count(TreeNode *root, vector<int> hash)
    {
        if(!root)
            return cnt;
        
        hash[root->val]+=1;
        if(!root->left && !root->right)
        {
            int odd=0;
            for(int i=0;i<10;i++)
                if(hash[i]%2)
                    odd++;
            
            if(odd<=1)
                cnt++;
            
            return cnt;
        }
        
        count(root->left, hash);
        count(root->right, hash);
        
        return cnt;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> hash(10, 0);
        
        return count(root, hash);
    }
};