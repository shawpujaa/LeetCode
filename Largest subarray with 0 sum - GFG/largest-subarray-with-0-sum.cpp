//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        
        if(n==1 && A[0]==0)
        return 1;
        
        int mxLen=-1, sum=0;
        map<int, int> mp;
        mp[0]=-1;
        
        for(int i=0;i<n;i++)
        {
            sum+=A[i];
            
            if(mp.find(sum)!=mp.end())
            mxLen=max(mxLen, i-(mp.find(sum))->second);
            else
            mp[sum]=i;
            
            
        }
        
        if(mp.find(sum)!=mp.end())
        mxLen=max(mxLen, n-mp.find(sum)->second-1);
        
        
        return mxLen;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends