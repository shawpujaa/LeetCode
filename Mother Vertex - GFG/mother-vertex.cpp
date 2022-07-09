// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    int mother=-1;
	    
	    for(int i=0;i<V;i++)
	    {
	        queue<int> q;
	        int visited[V]={0};
	        q.push(i);
	        visited[i]=1;
	        
	        while(!q.empty())
	        {
	            int node = q.front();
	            q.pop();
	            
	            for(int i=0;i<adj[node].size();i++)
	            {
	                if(!visited[adj[node][i]])
	                {
	                    q.push(adj[node][i]);
	                    visited[adj[node][i]]=1;
	                }
	            }
	        }
	        
	        bool flg=1;
	        
	        for(int j=0;j<V;j++)
	        {
	            if(!visited[j])
	            {
	                flg=0;
	                break;
	            }
	        }
	        
	        if(flg)
	        {
	            mother=i;
	            break;
	        }
	    }
	    
	    return mother;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends