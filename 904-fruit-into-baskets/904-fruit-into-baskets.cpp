class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int cnt=0;
        pair<int, int> basket1={fruits[0], 1}, basket2={-1, 0};
        
        for(int i=1, j=0;i<fruits.size();i++)
        {
            if(fruits[i]==basket1.first)
                basket1.second+=1;
            else if(basket2.first==fruits[i])
                basket2.second+=1;
            else if(basket2.first==-1)
            {
                basket2.first=fruits[i];
                basket2.second=1;
            }
            else
            {
                cnt=max(cnt, basket1.second+basket2.second);
                
                while(basket1.second!=0 && basket2.second!=0)
                {
                    if(fruits[j++]==basket1.first)
                        basket1.second-=1;
                    else
                        basket2.second-=1;
                }
                
                if(basket1.second==0)
                {
                    basket1.second=1;
                    basket1.first=fruits[i];
                }
                else
                {
                    basket2.second=1;
                    basket2.first=fruits[i];
                }
            }
        }
        
        cnt=max(cnt, basket1.second+basket2.second);
        
        return cnt;
    }
};