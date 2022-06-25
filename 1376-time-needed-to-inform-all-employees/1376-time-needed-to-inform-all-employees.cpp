class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int mxTime=-1;
        
        for(int i=0;i<n;i++)
        {
            int j=i, time=0;
            while(j!=headID)
            {
                j=manager[j];
                time+=informTime[j];
            }
            
            mxTime=max(mxTime, time);
        }
        
        return mxTime;
    }
};