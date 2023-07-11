//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void getPaths(int row, int col, string s, vector<string>& ans, int N, vector<vector<int>> m, vector<vector<bool>> matrix)
    {
        if(row==N-1 && col==N-1)
        {
            ans.push_back(s);
            return;
        }
        
        if(col>0 && m[row][col-1]==1 && matrix[row][col-1]==0)
        {
            s+='L';
            matrix[row][col-1]=1;
            
            getPaths(row, col-1, s, ans, N, m, matrix);
            
            s.pop_back();
            matrix[row][col-1]=0;
        }
        
        if(col<N-1 && m[row][col+1]==1 && matrix[row][col+1]==0)
        {
            s+='R';
            matrix[row][col+1]=1;
            
            getPaths(row, col+1, s, ans, N, m, matrix);
            
            s.pop_back();
            matrix[row][col+1]=0;
        }
        
        if(row>0 && m[row-1][col]==1 && matrix[row-1][col]==0)
        {
            s+='U';
            matrix[row-1][col]=1;
            
            getPaths(row-1, col, s, ans, N, m, matrix);
            
            s.pop_back();
            matrix[row-1][col]=0;
        }
        
        if(row<N-1 && m[row+1][col]==1 && matrix[row+1][col]==0)
        {
            s+='D';
            matrix[row+1][col]=1;
            
            getPaths(row+1, col, s, ans, N, m, matrix);
            
            s.pop_back();
            matrix[row+1][col]=0;
            
        }
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        
        if(m[n-1][n-1]==0 || m[0][0]==0)
        return ans;
        
        string s;
        vector<vector<bool>> matrix(n, vector<bool>(n, 0));
        matrix[0][0]=1;
        
        getPaths(0, 0, s, ans, n, m, matrix);
        
        return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends