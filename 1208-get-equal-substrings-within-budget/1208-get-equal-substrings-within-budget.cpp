class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxlength=0, n=s.size(), i=0, j=0;
        
        while(i<n)
        {
            if(maxCost>=abs(s[i]-t[i]))
            {
                maxCost-=abs(s[i]-t[i]);
                i++;
            }
            else
            {
                maxlength=max(maxlength, i-j);
                maxCost+=abs(s[j]-t[j]);
                j++;
            }
        }
        
        maxlength=max(maxlength, i-j);
        
        return maxlength;
    }
};