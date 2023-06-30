//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	/*int MinSquares(int n)
	{
	    // Code here
	    if(n==0)
	    return 0;
	    
	    int x = sqrt(n), mn=INT_MAX;
	    
	    for(int i=1;i<=x;i++)
	    mn=min(mn, n-(i*i));
	    
	    return mn+1;
	    
	}*/
	
	int squares(int n, vector<int>& dummy)
	{
	    if(n==0)
	    return 0;
	    
	    if(dummy[n]!=-1)
	    return dummy[n];
	    
	    int x = sqrt(n), mn=INT_MAX;
	    
	    for(int i=1;i<=x;i++)
	    mn=min(mn, squares(n-(i*i), dummy) );
	    
	    dummy[n]=mn+1;
	    
	    return dummy[n];
	    
	}
	
	int MinSquares(int n)
	{
	    vector<int> dummy(n+1, -1);
	    
	    return squares(n, dummy);
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends