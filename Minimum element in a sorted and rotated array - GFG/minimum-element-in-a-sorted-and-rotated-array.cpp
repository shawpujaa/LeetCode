// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        
        int left=0, right=n-1, mid;
        while(left<=right)
        {
            mid=(left+right)/2;
            
            if(left==mid && right==mid)
            return arr[mid];
            
            if(arr[mid]>=arr[0])
            {
                if(arr[n-1]<arr[0])
                left=mid+1;
                else
                right=mid;
            }
            else
            {
                right=mid;
            }
        }
    }
};

// { Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}  // } Driver Code Ends