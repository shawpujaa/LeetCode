class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st;
        int sum=0, mx=-1, j=0;
        
        for(int i=0;i<nums.size();i++)
        {
            while(st.find(nums[i])!=st.end())
            {
                sum-=nums[j];
                st.erase(nums[j]);
                j++;
            }
            sum+=nums[i];
            st.insert(nums[i]);
            
            mx=max(mx, sum);
        }
        
        return mx;
    }
};