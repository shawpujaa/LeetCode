class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        if(!numRows)
            return triangle;
        int x=0;
        vector<int> dummy1;
        
        while(x!=numRows)
        {
            vector<int> dummy2;
            for(int i=0;i<dummy1.size()+1;i++)
            {
                if(i==0 || i+1==x+1)
                    dummy2.push_back(1);
                else
                    dummy2.push_back(dummy1[i]+dummy1[i-1]);
            }
            
            triangle.push_back(dummy2);
            dummy1.clear();
            for(int i=0;i<dummy2.size();i++)
            {
                dummy1.push_back(dummy2[i]);
            }
            x++;
        }
        
        return triangle;
    }
};