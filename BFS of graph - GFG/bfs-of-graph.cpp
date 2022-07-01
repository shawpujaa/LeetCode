// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    /*vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        bool visited[V];
        queue<int> q;
        vector<int> bfs;
        
        q.push(0);
        visited[0]=1;
        
        while(!q.empty())
        {
            int x=q.front();
            bfs.push_back(x);
            q.pop();
            
            for(auto it:adj[x])
            {
                if(!visited[it])
                {
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
        
        return bfs;
    } */
    
    

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       unordered_map<int, bool> umap;
       vector<int> ans;
       queue<int> q;
       
       q.push(0);
       while(!q.empty())
       {
           int node=q.front();
           q.pop();
           ans.push_back(node);
           for(auto i: adj[node])
           {
               if(umap[i]!=true)
               {
                   q.push(i);
                   umap[i]=true;
               }
           }
       }
       return ans;
   }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends