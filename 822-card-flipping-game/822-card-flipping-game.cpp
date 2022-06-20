class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        multiset<pair<int, int>> mt;
        
        for(int i=0;i<fronts.size();i++)
            mt.insert({fronts[i], backs[i]});
        
        int ansfront=0, dont=0, ansback=0;
        
        for(auto it:mt)
        {
            if(it.first!=it.second && dont!=it.first)
            {
                if(ansfront==0)
                    ansfront=it.first;
                else if(ansfront!=it.first)
                    break;
            }
            else if(ansfront!=0 && ansfront!=it.first)
                    break;
            else
            {
                dont=it.first;
                ansfront=0;
            }
        }
        
        mt.clear();
        
        for(int i=0;i<fronts.size();i++)
            mt.insert({backs[i], fronts[i]});
        
        for(auto it:mt)
        {
            if(it.first!=it.second && dont!=it.first)
            {
                if(ansback==0)
                    ansback=it.first;
                else if(ansback!=it.first)
                    break;
            }
            else if(ansback!=0 && ansback!=it.first)
                    break;
            else
            {
                dont=it.first;
                ansback=0;
            }
        }
        
        if(ansfront==0)
            return ansback;
        else if(ansback==0)
            return ansfront;
            
        return (ansfront<ansback)? ansfront : ansback;
    }
};