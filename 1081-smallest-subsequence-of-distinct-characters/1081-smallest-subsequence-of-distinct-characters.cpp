class Solution {
public:
    string smallestSubsequence(string s) {
        int hash[26]={0};
        bool flag[26]={0};
        stack<char> st;
        string ans="";
        
        for(int i=0;i<s.size();i++)
            hash[s[i]-97]+=1;
        
        for(int i=0;i<s.size();i++)
        {
            hash[s[i]-97]-=1;
            if(flag[s[i]-97])
                continue;
            
            while(!st.empty() && st.top()>=s[i] && hash[st.top()-97]>0)
            {
                flag[st.top()-97]=0;
                st.pop();
            }
            
            st.push(s[i]);
            flag[s[i]-97]=1;
        }
        
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
       
        return ans;
    }
};