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
    TreeNode* toBST(vector<int> &nums, int low, int high)
    {
        if(low>=high)
            return 0;
        
        TreeNode *temp=new TreeNode(nums[(low+high)/2]);
        temp->left=toBST(nums, low, (low+high)/2);
        temp->right=toBST(nums, (low+high)/2+1, high);
        
        return temp;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBST(nums, 0, nums.size());
    }
};