class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0, j=0, res=0, cntOdd=0, cntEvn=1, n=nums.size();
        
        while(i<n)
        {
            while(i<n && cntOdd<k)
            {
                if(nums[i]%2)
                      cntOdd++;
                i++;
            }
            
            while(i<n && nums[i]%2!=1)
            {
                cntEvn++;
                i++;
            }
            
            while(cntOdd==k && j<(n-k) && nums[j]%2!=1)
            {
                j++;
                res+=cntEvn;
            }
            
            if(cntOdd==k)
            {
                j++;
                cntOdd--;
                res+=cntEvn;
                cntEvn=1;
            }
                  
        }
        
        return res;
    }
};