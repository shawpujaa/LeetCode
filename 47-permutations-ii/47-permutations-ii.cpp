class Solution {
public:
    bool check(int end, int start, vector<int> nums)
    {
        for(int i=start;i<end;i++)
            if(nums[i]==nums[end])
                return true;
        
        return false;
    }
    
    void recur(int index, vector<int> &nums, vector<vector<int>> &ans)
    {
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=index; i<nums.size(); i++)
        {
            if(check(i, index, nums))
                continue;
            
            swap(nums[i], nums[index]);
            recur(index+1, nums, ans);
            swap(nums[i], nums[index]);
            
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
     vector<vector<int>> ans;
        
        recur(0, nums, ans);
        
        return ans;
    }
};