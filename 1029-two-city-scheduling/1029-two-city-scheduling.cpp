class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        vector<pair<int, int>> benefit;
        
        for(int i=0;i<n;i++)
        {
            benefit.push_back(make_pair(abs(costs[i][0]-costs[i][1]),i));
        }
        
        sort(benefit.begin(), benefit.end());
        
        int min_cost=0, a=0, b=0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(a<n/2 && ((costs[benefit[i].second][0]<costs[benefit[i].second][1]) || b==n/2))
            {
                a++;
                min_cost+=costs[benefit[i].second][0];
            }
            else
            {
                b++;
                min_cost+=costs[benefit[i].second][1];
            }  
        }
        
        return min_cost;
    }
};