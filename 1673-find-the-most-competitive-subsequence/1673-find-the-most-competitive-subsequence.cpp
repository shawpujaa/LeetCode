class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> stk;
        int n=nums.size(), i=0;
        
        while(i<n)
        {
            while(!stk.empty() && (n-i+stk.size())>k && stk.top()>nums[i])
            {
                stk.pop();
                
                if(i==n)
                    break;
            }
            
            if(stk.size()<k)
                stk.push(nums[i]);
            
            i++;
        }
        
        vector<int> ans;
        
        for(int j=0;j<k;j++)
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};