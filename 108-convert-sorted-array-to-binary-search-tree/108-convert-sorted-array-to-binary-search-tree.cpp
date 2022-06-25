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
    TreeNode* createBST(vector<int> nums, int low, int high)
    {
        if(low>high)
            return 0;
        
        int mid=(low+high)/2;
        TreeNode *temp=new TreeNode(nums[mid]);
        temp->left=createBST(nums, low, mid-1);
        temp->right=createBST(nums, mid+1, high);
        
        return temp;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return createBST(nums, 0, nums.size()-1);
    }
};