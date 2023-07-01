//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> ans;
    
    vector<int> subsetSums(vector<int> arr, int N, int idx=0, int sum=0)
    {
        // Write Your Code here
        if(idx >= N)
        {
            ans.push_back(sum);
            return ans;
        }
        
        subsetSums(arr, N, idx+1, sum);
        subsetSums(arr, N, idx+1, sum+arr[idx]);
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends