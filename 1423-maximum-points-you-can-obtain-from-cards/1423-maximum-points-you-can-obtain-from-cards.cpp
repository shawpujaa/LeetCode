class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0,n=cardPoints.size(), mnSum=0, mn=0;
        
        for(int i=0;i<n;++i)
            sum+=cardPoints[i];
        k=n-k;
        
        int i=0, j=0;
        
        for(;j<k;j++)
            mnSum+=cardPoints[j];
        mn=mnSum;
        
        while(j<n)
        {
            mnSum+=cardPoints[j];
            mnSum-=cardPoints[i];
            i++;
            j++;
            
            mn=min(mnSum, mn);
        }
        
        return sum-mn;
    }
};