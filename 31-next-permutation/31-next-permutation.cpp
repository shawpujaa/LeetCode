class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j, n=nums.size();
        for(i=n-2;i>=0;i--)
        {
            if(nums[i+1]>nums[i])
                break;
        }
        
        if(i==-1)
        {
            for(i=0, j=n-1;i<j; i++, j--)
                swap(nums[i], nums[j]);
            
            return;
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
    }
    
};