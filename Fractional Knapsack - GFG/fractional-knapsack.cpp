//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(double W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double, int>> items;
        for(int i=0;i<n;i++)
        items.push_back({(arr[i].value)/double(arr[i].weight), i});
        
        sort( items.begin(), items.end(), greater<pair<double, int>>() );
        
        double mxValue=0;
        int idx=0;
        
        while(idx<n && W>0)
        {
            double wgt = (arr[(items[idx]).second]).weight;
            double val = (arr[(items[idx]).second]).value;
            
            if(W >= wgt)
            {
                mxValue += val;
                W -= wgt;
            }
            else
            {
                mxValue += (W/wgt)*val ;
                W=0;
            }
            
            idx+=1;
            
            
        }
        
        return mxValue;
        
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends