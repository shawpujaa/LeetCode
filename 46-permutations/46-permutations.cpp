class Solution {
public:
    void recur(int index, vector<vector<int>> &ans, vector<int> &nums)
    {
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index], nums[i]);
            recur(index+1, ans, nums);
            swap(nums[index], nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        recur(0, ans, nums);
        
        return ans;
    }
};