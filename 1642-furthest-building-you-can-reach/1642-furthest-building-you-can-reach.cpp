class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int i=1;
        
        for(;i<heights.size();i++)
        {
            if((heights[i]-heights[i-1])>0)
            {
                pq.push(heights[i]-heights[i-1]);
                
                if(pq.size()>ladders)
                {
                    bricks-=pq.top();
                    pq.pop();
                    
                    if(bricks<0)
                        break;
                }
                
            }
            
        }
        
        return i-1;
    }
};