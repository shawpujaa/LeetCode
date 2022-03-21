class Solution {
public:
    int nextGreaterElement(int n) {
        long x=n, d, i, ans=0;
        vector<int> num;
        
        while(x)
        {
            d=x%10;
            num.push_back(d);
            
            x/=10;
        }
        
        for(i=0;i<num.size()-1;i++)
        {
            if(num[i]>num[i+1])
            {
                int j=i, x=i;
                
                while(j>=0)
                {
                    if(num[j]<num[x] && num[j]>num[i+1])
                    {
                        x=j;
                    }
                    j--;
                }
                
                swap(num[i+1], num[x]);
                
                sort(num.begin(), num.begin()+i+1, greater<int>());
                
                break;
            }
        }
        
        
        for(i=0;i<num.size();i++)
        {
            long x=pow(10, i);
            ans+=(x*num[i]);
        }
        
        if(ans>n && ans<=2147483647)
            return ans;
        else
            return -1;
    }
};