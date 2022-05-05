class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> rowMax;
        vector<int> colMax;
        int n=grid[0].size(), mxSum=0;
        
        for(int i=0;i<n;i++)
        {
            int mx=-1;
            for(int j=0;j<n;j++)
            {
                mx=max(mx, grid[i][j]);
            }
            rowMax.push_back(mx);
        }
        
        for(int i=0;i<n;i++)
        {
            int mx=-1;
            for(int j=0;j<n;j++)
            {
                mx=max(mx, grid[j][i]);
            }
            colMax.push_back(mx);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mxSum+=(min(rowMax[i], colMax[j])-grid[i][j]);
            }
        }
        
        return mxSum;
    }
};