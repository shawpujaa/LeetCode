class Solution {
public:
    bool operat(string x)
    {
        if(x=="+" || x=="/" || x=="*" || x=="-")
            return true;
        
        return false;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        for(int i=0;i<tokens.size();i++)
        {
            
            if(operat(tokens[i]))
            {
                int x=s.top();
                s.pop();
                int y=s.top();
                s.pop();
                
                if(tokens[i]=="+")
                    s.push(x+y);
                else if(tokens[i]=="-")
                    s.push(y-x);
                else if(tokens[i]=="*")
                    s.push(y*x);
                else
                    s.push(y/x);
                
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
        }
        
        return s.top();
    }
};