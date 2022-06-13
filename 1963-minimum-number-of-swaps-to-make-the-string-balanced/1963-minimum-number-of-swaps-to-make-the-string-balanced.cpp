class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='[')
                stk.push(s[i]);
            else
            {
                if(!stk.empty() && stk.top()=='[')
                    stk.pop();
                else
                    stk.push(s[i]);
            }
        }
        
        int size=stk.size()/2;
        
        if(size%2)
            return size/2+1;
        
        return size/2;
    }
};