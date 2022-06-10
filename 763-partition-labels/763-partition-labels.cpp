class Solution {
public:
    vector<int> partitionLabels(string s) {
        int i=-1, mx=0, n=s.size(), j=0, hash[26]={-1};;
        vector<int> res;
        
        for(;j<n;j++)
        {
            hash[s[j]-97]=max(hash[s[j]-97], j);
        }
        j=0;
        
        while(j<n)
        {
            mx=max(mx, hash[s[j]-97]);
            if(mx==j)
            {
                res.push_back(mx-i);
                i=mx;
                mx++;
            }
            j++;
        }
        
        return res;
    }
};