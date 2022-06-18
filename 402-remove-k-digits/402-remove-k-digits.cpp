class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char> stk;
        
        int length=num.size()-k, i=0;
        
        while(i<num.size())
        {
            while(!stk.empty() && stk.top()>num[i] && (stk.size()+num.size()-i-1)>=length)
                stk.pop();
            
            stk.push(num[i]);
            i++;
        }
        
        string s="";
        
        while(!stk.empty())
        {
            s+=stk.top();
            stk.pop();
        }
        
        if(s.size()==0)
            return "0";
        
        reverse(s.begin(), s.end());
        
        while(length<s.size())
            s.pop_back();
        
        while(s[0]=='0')
            s.erase(s.begin());
        
        if(s.size()==0)
            return "0";
        
        return s;
    }
};