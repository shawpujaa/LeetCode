class Solution {
public:
    string decodeString(string s) {
        string ans="";
        int i=0;
        stack<pair<string, string>> st;
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
                            if(st.top().second!=" ")
                                dummy=dummy + st.top().first + st.top().second;
                            else
                                dummy=dummy + st.top().first;
                        }
                        st.pop();
                        freq.pop();
                        
                        if(st.size()>0)
                        {
                            string str1=st.top().first, str2;
                            if(st.top().second!=" ")
                                str2=st.top().second+dummy;
                            else
                                str2=dummy;
                            st.pop();
                            st.push({str1, str2});
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
                
                    st.push({str," "});
                     
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
                        string str1=st.top().first, str2;
                        if(st.top().second!=" ")
                                str2=st.top().second+str;
                            else
                                str2=str;
                        st.pop();
                        st.push({str1, str2});
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