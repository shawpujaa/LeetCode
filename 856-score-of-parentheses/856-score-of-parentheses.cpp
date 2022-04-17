class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string> st;
        
        for(int i=0;i<s.size();i++)
        {
            int y=0;
            if(s[i]=='(')
                st.push("(");
            else 
            {
                if(st.top()=="(")
                {
                    st.pop();
                    st.push("1");
                }
                else
                {
                    while(!st.empty() && st.top()!="(")
                    {
                        y+=stoi(st.top());
                        st.pop();
                    }
                    
                    st.pop();
                    st.push(to_string(2*y));
                }
            }
        }
        
        int ans=0;
        while(!st.empty())
        {
            ans+=stoi(st.top());
            st.pop();
        }
        
        return ans;
    }
};