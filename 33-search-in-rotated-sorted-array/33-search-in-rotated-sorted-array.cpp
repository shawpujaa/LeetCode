class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n=nums.size();
        int left=0, right=n-1, mid;
        
        while(left<=right)
        {
            mid=(left+right)/2;
            
            if(nums[mid]==target)
                return mid;
            
            if(nums[mid]>=nums[0])
            {
                if(nums[mid]>target)
                {
                    if(nums[left]>target)
                        left=mid+1;
                    else
                        right=mid-1;
                }
                else
                {
                    left=mid+1;
                }
            }
            else
            {
                if(nums[mid]>target)
                {
                    right=mid-1;
                }
                else
                {
                    if(nums[right]<target)
                        right=mid-1;
                    else
                        left=mid+1;
                }
            }
        }
        
        return -1;
    }
};