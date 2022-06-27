class Solution {
public:
    int minPartitions(string n) {
        int mx=-1;
        
        for(int i=0;i<n.size();i++)
        {
            int x=n[i]-48;
            mx=max(mx, x);
        }
        
        return mx;
    }
};