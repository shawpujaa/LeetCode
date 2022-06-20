class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        set<int> same;
        
        for(int i=0;i<fronts.size();i++)
        {
            if(fronts[i]==backs[i])
                same.insert(fronts[i]);
        }
        
        int ans=INT_MAX;
        
        for(int i=0;i<fronts.size();i++)
        {
            if(same.find(fronts[i])==same.end())
            ans=min(ans, fronts[i]);
            
            if(same.find(backs[i])==same.end())
            ans=min(ans, backs[i]);
        }
        
        if(ans==INT_MAX)
            return 0;
        
        return ans;
    }
};