// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        
        long long cnt=0, x=0;
        
        unordered_map<int, int> mp;
        mp[0]+=1;
        
        for(long long i=0;i<n;i++)
        {
            if(arr[i])
            x++;
            else
            x--;
            
            if(mp.find(x)!=mp.end())
                cnt+=mp[x];
            
            mp[x]+=1;
        }
        
        return cnt;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends