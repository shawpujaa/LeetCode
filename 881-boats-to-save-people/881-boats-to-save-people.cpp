class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats=0;
        
        sort(people.begin(), people.end());
        
        for(int i=0, j=people.size()-1;i<=j;)
        {
            if((people[i]+people[j])<=limit)
            {
                i++;j--;
            }   
            else
            {
                j--;
            }
            boats++;
        }
        
        return boats;
    }
};