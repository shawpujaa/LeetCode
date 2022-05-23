class Solution {
public:
    int getNumber(string s, char x, int i)
    {
        long long num=0;
        while(s[i]>=48 && s[i]<=57 && i<s.size())
        {  
            num=num*10+(s[i]-48);
            i++;
            if(num>2147483647)
                break;
        }
        
        if(x==45)
            num*=-1;
        
        if(num>2147483647)
            num=2147483647;
        else if(num<-2147483648)
            num=-2147483648;
        
        return num;
    }
    
    int myAtoi(string s) {
        int num=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==32)
                continue;
            else if(s[i]==45 || s[i]==43)
            {
                num=getNumber(s, s[i] , i+1);
                break;
            }
            else if(s[i]>=48 && s[i]<=57)
            {
                num=getNumber(s, 43, i);
                break;
            }
            else
                break;
        }
        
        return num;
    }
};