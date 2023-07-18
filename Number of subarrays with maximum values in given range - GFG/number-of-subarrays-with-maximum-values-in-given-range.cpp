//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
        int mx=INT_MIN, low=-1, x=-1;
        long long count=0;
        
        for(int i=0;i<n;i++)
        {
            if(a[i] >= L && a[i] <= R)
            {
                count += (i-low);
                mx = max(mx, a[i]);
                
                x=-1;
            }
            else if(a[i] < L)
            {
                if(mx >= L && mx <= R)
                {
                    if(x==-1)
                    {
                        count += (i-low-1);
                        x=i;
                    }
                    else
                    count += (x-low-1);
                }
                
            }
            else
            {
                mx=INT_MIN;
                low=i;
                x=-1;
            }
            
        }
        
        return count;
        
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends