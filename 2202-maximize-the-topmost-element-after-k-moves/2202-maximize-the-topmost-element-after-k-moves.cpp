class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        
        if(n==1)
        {
            if(k%2)
                return -1;
            
            return nums[0];
        }
        
        if(k==1)
            return nums[1];
        
        int mx=nums[0], i=0;
        
        while(i<n && i<k-1)
        {
            mx=max(mx, nums[i]);
            i++;
        }
        
        if(i!=n && i+1!=n && i==k-1)
        {
            mx=max(mx, nums[i+1]);
        }
        
        return mx;
    }
};