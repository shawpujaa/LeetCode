class Solution {
public:
    bool operat(string x)
    {
        if(x=="+" || x=="/" || x=="*" || x=="-")
            return true;
        
        return false;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        
        for(int i=0;i<tokens.size();i++)
        {
            
            if(operat(tokens[i]))
            {
                int x=stoi(s.top());
                s.pop();
                int y=stoi(s.top());
                s.pop();
                
                if(tokens[i]=="+")
                    s.push(to_string(x+y));
                else if(tokens[i]=="-")
                    s.push(to_string(y-x));
                else if(tokens[i]=="*")
                    s.push(to_string(y*x));
                else
                    s.push(to_string(y/x));
                
            }
            else
            {
                s.push(tokens[i]);
            }
        }
        
        return stoi(s.top());
    }
};