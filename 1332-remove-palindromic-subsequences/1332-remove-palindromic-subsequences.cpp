class Solution {
public:
    int removePalindromeSub(string s) {
        int flag=0;
        
        for(int i=0, j=s.size()-1 ;j>i ; i++, j--)
        {
            if(s[i]!=s[j])
            {
                flag=1;
                break;
            }
        }
        
        if(flag)
            return 2;
        
        return 1;
    }
};