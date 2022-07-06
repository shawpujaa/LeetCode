class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(); 
        
        if(n<2)
            return n;
        
        sort(nums.begin(), nums.end());
        int cnt=1, prev=nums[0], ans=1;
        
        for(int i=1;i<n;i++)
        {
            if(prev+1==nums[i])
                cnt++;
            else if(prev+1<nums[i])
            {
                ans=max(ans, cnt);
                cnt=1;
            }
            
            prev=nums[i];
        }
        ans=max(ans, cnt);
        
        return ans;
    }
};