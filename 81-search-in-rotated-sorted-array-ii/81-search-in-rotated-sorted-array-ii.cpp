class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0, right=n-1, mid;
        
        while(left<=right)
        {
            mid=(left+right)/2;
            
            if(nums[mid]==target)
                return true;

            if(nums[left]==nums[mid] && nums[mid]==nums[right])
            {
                left++;
                right--;
                continue;
            }   

            if(nums[mid]>=nums[left])
            {
                if(target>nums[mid])
                {
                    left=mid+1;
                }
                else
                {
                    if(target>=nums[left])
                    {
                     right=mid-1;
                    }
                    else
                        left=mid+1;
                }
                    
            }
            else
            {
                if(target<nums[mid])
                {
                    right=mid-1;
                }
                else
                {
                    if(target>nums[right])
                    {
                        right=mid-1;
                    }
                    else
                        left=mid+1;
                }
            }
        }
        
        return false;
    }
};