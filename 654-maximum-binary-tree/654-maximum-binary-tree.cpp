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
    TreeNode* construct(vector<int>& nums, int low, int high)
    {
        if(low>=high)
            return 0;
        
        int mx=-1, idx=-1;
        
        for(int i=low;i<high;i++)
        {
            if(mx<nums[i])
                mx=nums[i], idx=i;
        }
        
        TreeNode *temp=new TreeNode(mx);
        
        temp->left=construct(nums, low, idx);
        temp->right=construct(nums, idx+1, high);
        
        return temp;

    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return construct(nums, 0, nums.size());
        
            }
};