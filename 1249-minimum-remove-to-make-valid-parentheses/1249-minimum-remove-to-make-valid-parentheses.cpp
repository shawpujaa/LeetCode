class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<int, char>> st;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')' && !st.empty() && st.top().second=='(')
                st.pop();
            else if(s[i]=='(' || s[i]==')')
                st.push({i, s[i]});
        }
        
        string ans="";
        
        for(int i=s.size()-1;i>=0;i--)
        {
            if(!st.empty() && st.top().first==i)
                st.pop();
            else
                ans+=s[i];  
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};