class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0, j=1;j<n && i<n;)
        {
            if(nums[i]==0 && nums[j]!=0 && j>i)
                swap(nums[i], nums[j]);
            
            if(nums[i]!=0)
                i++;
            if(nums[j]==0 || j<i)
                j++;
                
        }
    }
};