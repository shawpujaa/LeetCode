class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> res;
        
        if(tomatoSlices%2 || tomatoSlices<2*cheeseSlices || tomatoSlices>4*cheeseSlices)
            return res;
        
        int small=cheeseSlices, jumbo=0;
        
        while((2*small + 4*jumbo)!=tomatoSlices)
        {
            if((2*small + 4*jumbo)<tomatoSlices)
            {
                small--;
                jumbo++;
            }
        }
        
        res.push_back(jumbo);
        res.push_back(small);
        
        return res;
    }
};