class Solution {
public:
    int maxDistance(vector<int>& colors) {
     
        int ans=-1, n=colors.size();
        for(int i=n-1;i>0;i--)
        {
            if(colors[i]!=colors[0])
            {
                int x=max(i, n-i-1);
                ans=max(ans,x);
            }
        }
        
        return ans;
    }
};