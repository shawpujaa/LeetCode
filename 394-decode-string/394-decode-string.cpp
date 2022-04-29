class Solution {
public:
    string decodeString(string s) {
        string ans="";
        int i=0;
        stack<string> st;
        stack<int> freq;
        
        while(i<s.size())
        {
            string dummy="";
            while(true)
            {
                if(s[i]==']')
                {
                    while(i<s.size() && s[i]==']')
                    {
                        i++;
                        for(int j=0;j<freq.top();j++)
                        {
                            dummy=dummy + st.top();
                        }
                        st.pop();
                        freq.pop();
                        
                        if(st.size()>0)
                        {
                            st.top()=st.top()+dummy;
                            
                            dummy.erase();
                        }
                        
                    }
                }
                else if(s[i]>=47 && s[i]<=58)
                {
                    string str="";
                    while(s[i]>=48 && s[i]<=57)
                    {
                        str=str+s[i];
                        i++;
                    }
                    freq.push(stoi(str));
                    i++;   str.erase();
                    
                    while(s[i]>=97 && s[i]<=122)
                    {
                        str=str+s[i];
                        i++;
                    }
                
                    st.push(str);
                     
                }
                else
                {
                    string str="";
                    while(i<s.size() && s[i]>=97 && s[i]<=122)
                    {
                        str=str+s[i];
                        i++;
                    } 
                    
                    if(!st.empty())
                    {
                            st.top()=st.top()+str;
                    }   
                    else
                        dummy=dummy+str;
                }
                
                if(st.empty())
                    break;
            }
            
            ans=ans+dummy;
        }
        
        return ans;
    }
};