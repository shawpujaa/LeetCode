class Solution {
public:
   /*  TC-O(N^2)
   
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
    } */
    
    // TC-O(NLogN) SC-O(N)
   /* int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_set<int> st;
        
        for(int i=0;i<n;i++)
            st.insert(i);
        
        for(int i=0;i<n;i++)
            st.erase(manager[i]);
        
        int mxTime=-1;
        for(auto it:st)
        {
            int j=it, time=0;
            while(j!=headID)
            {
                j=manager[j];
                time+=informTime[j];
            }
            
            mxTime=max(mxTime, time);
        }
        
        return mxTime;
    } */
    
    // TC-O(N) SC-O(1)
    
    int dfs_Time(int idx, vector<int> &manager, vector<int> &informTime)
    {
        if(manager[idx]!=-1)
        {
            informTime[idx]+=dfs_Time(manager[idx], manager, informTime);
            manager[idx]=-1;
        }
        
        return informTime[idx];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int mxTime=-1;
        
        for(int i=0;i<n;i++)
        {
            mxTime=max(mxTime, dfs_Time(i, manager, informTime));
        }
        
        return mxTime;
    }
};