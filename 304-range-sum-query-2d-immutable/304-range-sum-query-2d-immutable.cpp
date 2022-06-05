class NumMatrix {
public:
    vector<vector<int>> SumUpto;
    NumMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size(), col=matrix[0].size();
        
        SumUpto=vector<vector<int>>(row, vector<int>(col, 0));
        SumUpto[0][0]=matrix[0][0];
        
        // first row
        for(int i=1;i<col;i++)
            SumUpto[0][i]=matrix[0][i]+SumUpto[0][i-1];
        
        // first col
        for(int i=1;i<row;i++)
            SumUpto[i][0]=matrix[i][0]+SumUpto[i-1][0];
        
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
                SumUpto[i][j]=matrix[i][j]+SumUpto[i][j-1]+(SumUpto[i-1][j]-SumUpto[i-1][j-1]);
            
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(!row1 && !col1)
            return SumUpto[row2][col2];
        
        if(!row1 && col1)
            return SumUpto[row2][col2]-SumUpto[row2][col1-1];
        
        if(row1 && !col1)
            return SumUpto[row2][col2]-SumUpto[row1-1][col2];
        
        return SumUpto[row2][col2]-SumUpto[row2][col1-1]-SumUpto[row1-1][col2]+SumUpto[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */