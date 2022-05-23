class Solution {
public:
    bool nextPerm(vector<vector<int>> &ans, vector<int> &nums)
    {
        int i,j, n=nums.size();
        for(i=n-2;i>=0;i--)
        {
            if(nums[i+1]>nums[i])
                break;
        }
        
        if(i==-1)
        {
            return false;
        }
        
        for(j=n-1;j>i;j--)
        {
            if(nums[i]<nums[j])
                break;
        }
        
        swap(nums[i], nums[j]);
        
        //for swapping
        i++;
        for(j=n-1; j>i; j--,i++)
        {
            swap(nums[i], nums[j]);
        }
        
        ans.push_back(nums);
        
        return true;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        ans.push_back(nums);

        while(nextPerm(ans, nums));
              
        return ans;
    }
};