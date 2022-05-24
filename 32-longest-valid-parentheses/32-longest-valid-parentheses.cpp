class Solution {
public:
    int longestValidParentheses(string s) {
        
        if(!s.size())
            return 0;
        
        stack<pair<int, char>> stk;
        int n=s.size(), ans=0, flag=0;
       
        for(int i=0;i<n;i++)
        {
            if(!stk.empty() && stk.top().second=='(' && s[i]==')')
                stk.pop();
            else
                stk.push({i+1, s[i]});
        }
        
        if(stk.empty())
            return n;
        
        while(!stk.empty())
        {
            if(!flag)
            {
                ans=max(ans, n-stk.top().first);
                flag=1;
            }
            else
            ans=max(ans, n-stk.top().first-1);
            
            n=stk.top().first;
            stk.pop();
        }
        
        ans=max(ans, n-1);
        
        return ans;
    }
};