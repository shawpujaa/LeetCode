class Solution {
public:
    bool traverse(string s, int i, int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return true;
            
            i++; j--;
        }
        
        return false;
    }
    
    bool validPalindrome(string s) {
       int i=0, j=s.size()-1;
        bool flag1=0, flag2=0, flag3=0;
        
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                
                if(s[i+1]==s[j] && s[j-1]!=s[i])
                {
                    i++; 
                    if(traverse(s, i, j))
                        return false;
                    
                    return true;
                    
                }    
                else if(s[i]==s[j-1] && s[i+1]!=s[j])
                {
                    j--;
                    if(traverse(s, i, j))
                        return false;
                    
                    return true;
                    
                }
                else
                {
                    if(traverse(s, i+1, j))
                    {
                        if(traverse(s, i, j-1))
                        {
                            return false;
                        }
                        
                        return true;
                    }
                    
                    return true;
                }
               
            }
            i++; j--;
        }
        
        return true;
    }
};