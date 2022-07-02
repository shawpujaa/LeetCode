// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void traverse(vector<int> &dfs, int x, vector<int> adj[], bool visited[])
    {
        if(visited[x]==0)
        {
            dfs.push_back(x);
            visited[x]=1;
            
            for(int i=0;i<adj[x].size();i++)
                traverse(dfs, adj[x][i], adj, visited);
                
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[], int x=0) {
        // Code here
       vector<int> dfs;
       bool visited[V]={false};
       
       traverse(dfs, 0, adj, visited);
       
       return dfs;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends