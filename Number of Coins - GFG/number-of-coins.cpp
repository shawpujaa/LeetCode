//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	/*int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    
	    if(V==0)
	    return 0;
	    
	    int mn=INT_MAX;
	    
	    for(int i=0;i<M;i++)
	    {
	        if(coins[i] <= V)
	        mn=min(mn, minCoins(coins, M, V-coins[i]));
	    }
	    
	    if(mn==INT_MAX)
	    return mn;
	    
	    return mn+1;
	    
	}  */
	
/*	int cntCoins(int coins[], int M, int V, vector<int>& dummy)
	{
	    if(V==0)
	    return 0;
	    
	    if(dummy[V] != -1)
	    return dummy[V];
	    
	    int mn=INT_MAX;
	    
	    for(int i=0;i<M;i++)
	    {
	        if(coins[i] <= V)
	        mn=min(mn, cntCoins(coins, M, V-coins[i], dummy));
	    }
	    
	    if(mn!=INT_MAX)
	    dummy[V]=mn+1;
	    else
	    dummy[V]=mn;
	    
	    return dummy[V];
	    
	}
	
	int minCoins(int coins[], int M, int V)
	{
	    vector<int> dummy(V+1, -1);
	    
	    int cnt = cntCoins(coins, M, V, dummy);
	    
	    if(cnt==INT_MAX)
	    return -1;
	    
	    return cnt;
	    
	    
	}   */
	
	
	int minCoins(int coins[], int M, int V)
	{
	    vector<int> dummy(V+1, INT_MAX);
	    dummy[0]=0;
	    
	    for(int i=1;i<=V;i++)
	    {
	        int mn=INT_MAX;
	        for(int j=0;j<M;j++)
	        {
	            if(coins[j] <= i)
	            mn=min(mn, dummy[i-coins[j]]);
	        }
	        
	        if(mn!=INT_MAX)
	        dummy[i]=mn+1;
	    }
	    
	    if(dummy[V]==INT_MAX)
	    return -1;
	    
	    return dummy[V];
	    
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends