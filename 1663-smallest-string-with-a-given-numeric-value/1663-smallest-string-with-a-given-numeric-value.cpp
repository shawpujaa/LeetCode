class Solution {
public:
    string getSmallestString(int n, int k) {
        string s;
        
        while(n--)
        {
            int x=k-n*26;
            
            if(x<1)
            {
                s+='a';
                k--;
            }
            else
            {
                s+=x+96;
                k-=x;
            }
            
        }
        
        return s;
    }
};