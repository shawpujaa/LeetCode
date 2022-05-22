class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> sRow, sCol;
        int row=matrix.size(), col=matrix[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]==0)
                {
                    sRow.insert(i);
                    sCol.insert(j);
                }
            }
        }
        
        for(auto i=sRow.begin();i!=sRow.end();i++)
        {
            for(int j=0;j<col;j++)
            {
                matrix[*i][j]=0;
            }
        }
        
        for(auto i=sCol.begin();i!=sCol.end();i++)
        {
            for(int j=0;j<row;j++)
            {
                matrix[j][*i]=0;
            }
        }
    }
};