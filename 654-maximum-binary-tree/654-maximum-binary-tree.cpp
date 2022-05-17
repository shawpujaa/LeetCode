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
    TreeNode* create(vector<int> nums, int low, int high)
    {
        if(low>=high)
            return nullptr;
        
        int idx=low;
        for(int i=low;i<high;i++)
        {
            if(nums[idx]<nums[i])
                idx=i;
        }
        TreeNode *temp=new TreeNode(nums[idx]);
        
        temp->left=create(nums, low, idx);
        temp->right=create(nums, idx+1, high);
        
        return temp;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return create(nums, 0, nums.size());
    }
};