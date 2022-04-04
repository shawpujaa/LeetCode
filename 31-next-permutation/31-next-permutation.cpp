class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1)
            return;
        if(n==2)
        {
            swap(nums[0], nums[1]);
            
            return;
        }
        
        int i=n-1;
        for(;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                int j=n-1;
                
                while(j>i && nums[j]<=nums[i-1])
                    j--;
                
                swap(nums[j], nums[i-1]);
                break;
            }
        }
        
        for(int j=n-1;i<j;i++, j--)
        {
            swap(nums[i], nums[j]);
        }
    }
};