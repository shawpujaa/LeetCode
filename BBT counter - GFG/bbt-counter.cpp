//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int countBT(int h) { 
        // code here
        
        if(h <= 1)
        return 1;
        
        long long a=1, b=1, mod = pow(10,9) + 7;
        
        for(int i=2;i<=h;i++)
        {
            int temp1 = (b*b) % mod;
            int temp2 = (2*a*b) % mod;
            
            long long c = (temp1 + temp2) % mod;
            
            a=b;
            b=c;
        }
        
        return b;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}

// } Driver Code Ends