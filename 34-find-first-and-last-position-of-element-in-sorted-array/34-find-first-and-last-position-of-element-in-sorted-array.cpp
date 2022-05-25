class Solution {
public:
    int lowerBound(vector<int> nums, int target)
    {
        int low=0, high=nums.size()-1, mid, bound=-1;
        
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==target)
            {
                bound=mid;
                high=mid-1;
                continue;
            }
            
            if(nums[mid]<target)
                low=mid+1;
            
            if(nums[mid]>target)
                high=mid-1;
        }
        
        return bound;
    }
    
    int upperBound(vector<int> nums, int target)
    {
        int low=0, high=nums.size()-1, mid, bound=-1;
        
        while(low<=high)
        {
            mid=(low+high)/2;
            
            if(nums[mid]==target)
            {
                bound=mid;
                low=mid+1;
                continue;
            }
            
            if(nums[mid]<target)
                low=mid+1;
            
            if(nums[mid]>target)
                high=mid-1;
        }
        
        return bound;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)
            return {-1, -1};
        
        vector<int> pos;
        
        pos.push_back(lowerBound(nums, target));
        pos.push_back(upperBound(nums, target));
        cout<<"c";
        return pos;
    }
};