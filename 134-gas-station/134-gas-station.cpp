class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(), idx=-1, i=0;
        
        while(i<n)
        {
            int fuel=gas[i]-cost[i];
            int j=(i+1)%n;
                
            while(fuel>=0 && j!=i)
            {
                fuel+=(gas[j]-cost[j]);
                j=(j+1)%n;
            }
                
            if(fuel<0)
            {
                if(j<=i)
                   break;
                else
                   i=j;
            }
                
            if(fuel>=0 && j==i)
            {
                idx=i;
                break;
            }
        
            
        }
        
        return idx;
    }
};