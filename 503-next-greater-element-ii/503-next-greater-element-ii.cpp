class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int> ans(nums.size(), -1);
        stack<int> s;
        
        int i=0, count=0;
        
        while(count<(2*nums.size()))
        {
            count++;
            
            while(!s.empty() && nums[s.top()]<nums[i])
            {
                ans[s.top()]=nums[i];
                s.pop();
            }
            
            if(count<=nums.size())
            s.push(i);
            
            if(s.empty())
                break;
            
            i=(i+1)%nums.size();
        }
        
        return ans;
    }
};