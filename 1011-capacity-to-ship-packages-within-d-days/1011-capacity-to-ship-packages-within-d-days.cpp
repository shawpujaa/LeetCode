class Solution {
public:
    int Days(vector<int> weights, int cap)
    {
        long long sum=0, days=0;
        
        for(int i=0;i<weights.size();i++)
        {
            sum+=weights[i];
            
            if(sum>=cap)
            {
                if(sum==cap)
                    sum=0;
                else
                    sum=weights[i];
                
                days++;
            }
        }
        
        if(sum!=0)
            days++;
       
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN, high=0, n=weights.size(), mid, ans=INT_MAX;
    
        for(int i=0;i<n;i++)
        {
            low=max(low, weights[i]);
            high+=weights[i];
        }
        
        while(low<=high)
        {
            mid=(low+high)/2;
            int daysTaken=Days(weights, mid);
            
            if(daysTaken<=days)
            {
                if(daysTaken<days)
                    ans=min(ans, mid);
                else
                    ans=mid;
               
                high=mid-1;
            }
            
            if(daysTaken>days)
                low=mid+1;
            
        }
        if(ans==INT_MAX)
            return low;
        
        return ans;
    }
};