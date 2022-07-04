class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==1)
            return 1;
        
        vector<pair<int, int>> children;
        int n=ratings.size(), cnt=0;
        vector<int>candies(n, 1);
        
        for(int i=0;i<n;i++)
            children.push_back({ratings[i], i});
        
        sort(children.begin(), children.end());
        
        for(int i=0;i<n;i++)
        {
            if(children[i].second==0 && ratings[0]>ratings[1])
                candies[0]=candies[1]+1;
            else if(children[i].second==n-1 && ratings[n-1]>ratings[n-2])
                candies[n-1]=candies[n-2]+1;
            else if(children[i].second>0 && children[i].second<n-1)
            {
                if(ratings[children[i].second-1]<children[i].first && ratings[children[i].second+1]<children[i].first)
                {
                    candies[children[i].second]=max(candies[children[i].second-1], candies[children[i].second+1]) + 1;
                }
                else if(ratings[children[i].second-1]<children[i].first || ratings[children[i].second+1]<children[i].first)
                {
                    if(ratings[children[i].second-1]<children[i].first)
                        candies[children[i].second]=candies[children[i].second-1]+1;
                    else
                        candies[children[i].second]=candies[children[i].second+1]+1;
                    
                }
            }
                
        }
        
        for(int i=0;i<n;i++)
            cnt+=candies[i];
        
        return cnt;
    }
};