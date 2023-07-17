//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        map<int, int> mp;
        
        int sum=0, ans=0;
        mp[0]=-1;
        
        for(int i=0;i<N;i++)
        {
            sum += A[i];
            
            if(mp.find(sum-K) != mp.end())
            ans = max(ans, i - (mp.find(sum-K))->second);
            
            
            if(mp.find(sum) == mp.end())
            mp[sum] = i;
            
            
        }
        
        return ans;
        
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends