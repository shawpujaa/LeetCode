class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       // set<int> sRow, sCol;
        int row=matrix.size(), col=matrix[0].size();
        bool cols=0, rows=0;
       // for cols
        for(int i=0;i<col;i++)
        {
            if(matrix[0][i]==0)
            {
                cols=1;
                //matrix[0][0]=0;
            }
        }
        
        //for rows
        for(int i=0;i<row;i++)
        {
            if(matrix[i][0]==0)
            {
                rows=1;
               // matrix[0][0]=0;
            }
        }
        
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        
        for(int i=1;i<row;i++)
        {
            if(matrix[i][0]==0)
            {
                for(int j=0;j<col;j++)
                    matrix[i][j]=0;
            }
        }
        
        for(int i=1;i<col;i++)
        {
            if(matrix[0][i]==0)
            {
                for(int j=0;j<row;j++)
                    matrix[j][i]=0;
            }
        }
        
        if(rows)
        {
            for(int i=0;i<row;i++)
            matrix[i][0]=0;
        }
            
        if(cols)
        {
            for(int i=0;i<col;i++)
            matrix[0][i]=0;
        }
        
    }
};