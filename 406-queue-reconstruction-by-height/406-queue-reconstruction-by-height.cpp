class Solution {
public:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[1] < v2[1];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), sortcol);
        
        vector<vector<int>> res;
        res.push_back(people[0]);
        
        for(int i=1;i<people.size();i++)
        {
            int x=people[i][1], j=0;
            for(;j<res.size();j++)
            {
                if(res[j][0]>=people[i][0])
                    x--;
                
                if(x<0)
                    break;
                
            }
            
            res.insert(res.begin()+j, people[i]);
        }
        
        return res;
    }
};