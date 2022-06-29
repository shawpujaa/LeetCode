class Solution {
public:
    static bool sortcol(const vector<int> &v1, const vector<int> &v2)
    {
        return v1[1] < v2[1];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> height;
        
        sort(people.begin(), people.end(), sortcol);
       /* 
        for(int i=0;i<people.size();i++)
        {
            cout<<people[i][0]<<" "<<people[i][1]<<"\n";
        }*/
        
        for(int i=0;i<people.size();i++)
        {
            int x=0, j=0;
            while(j<height.size())
            {
                if(height[j][0]>=people[i][0])
                {
                    if(x<people[i][1])
                        x++;
                    else
                        break;
                }
                
                j++;
            }
     
            height.insert(height.begin()+j, people[i]);
        }
        
        return height;
    }
};