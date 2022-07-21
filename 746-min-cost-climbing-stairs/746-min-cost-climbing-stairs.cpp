class Solution {
public:
    // gives tle, recursive way----tc O(2^n) + stack space
   /* int reqCost(vector<int> cost, int idx, int minCost, int n)
    {
        if(idx==n-1)
            return minCost+cost[idx];
        else if(idx>=n)
            return minCost;
        
        return min(reqCost(cost, idx+1, minCost+cost[idx], n), reqCost(cost, idx+2, minCost+cost[idx], n));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        return min(reqCost(cost, 0, 0, cost.size()), reqCost(cost, 1, 0, cost.size()));
    }  */
    
    
    // memoization --------
    int reqCost(vector<int> cost, int idx, vector<int> &memo, int n)
    {
        if(idx==n-1)
        {
            memo[idx]=cost[idx];
            return memo[idx];
        }
        else if(idx>=n)
            return 0;
        
        if(memo[idx] != -1)
            return memo[idx];
        
        int x=reqCost(cost, idx+1, memo, n);
        int y=reqCost(cost, idx+2, memo, n);
        
        memo[idx]=min(x, y)+cost[idx];

        return memo[idx];
    }
    
    int minCostClimbingStairs(vector<int>& cost)
    {
        vector<int> memo(cost.size()+1, -1);
        
        return min(reqCost(cost, 0, memo, cost.size()), reqCost(cost, 1, memo, cost.size()));
    }
};