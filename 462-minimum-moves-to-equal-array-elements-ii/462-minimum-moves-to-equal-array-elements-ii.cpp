class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
        int median=nums[n/2], cnt=0;
        for(int i=0;i<n;i++)
            cnt+=abs(nums[i]-median);  //cnt+=abs(nums[i]-nums[j]);
        
        return cnt;
    }
};