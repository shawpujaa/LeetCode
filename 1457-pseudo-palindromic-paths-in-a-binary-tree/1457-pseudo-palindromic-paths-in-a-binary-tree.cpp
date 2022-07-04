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
    // Method 1---
   /* int cnt=0;
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
    }  */
    
    // Method 2---
    
   /* int cnt=0;
    int count(TreeNode *root, unordered_set<int> st)
    {
        if(!root)
            return cnt;
        
        if(st.find(root->val)==st.end())
            st.insert(root->val);
        else
            st.erase(root->val);
        
        if(!root->left && !root->right)
        {
            if(st.size()<=1)
                cnt++;
            
            return cnt;
        }
        
        count(root->left, st);
        count(root->right, st);
        
        return cnt;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_set<int> st;
        
        return count(root, st);
    }  */
    
    // Method 3-----
    
    int cnt=0;
    int count(TreeNode *root, int bitPath)
    {
        if(!root)
            return cnt;
        
        bitPath^=1<<root->val;
        
        if(!root->left && !root->right)
        {
            if(ceil(log2(bitPath)) == floor(log2(bitPath)))
                cnt++;
            
            return cnt;
        }
        
        count(root->left, bitPath);
        count(root->right, bitPath);
        
        return cnt;
    }
    
    int pseudoPalindromicPaths(TreeNode *root)
    {
        int bitPath=0;
        
        return count(root, bitPath);
    }
};