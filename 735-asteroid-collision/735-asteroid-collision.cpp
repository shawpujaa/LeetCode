class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> ans;
        
        for(int i=asteroids.size()-1; i>=0; i--)
        {
            while(!s.empty() && (s.top()<0 && asteroids[i]>0) )
            {
                if(abs(s.top()) > abs(asteroids[i]))
                {
                    i--;
                    if(i<0)
                    break;
                }
                else if(abs(s.top())==abs(asteroids[i]))
                {
                    s.pop();
                    i--;
                    if(i<0)
                    break;
                }
                else
                {
                    s.pop();
                }
            }
            
            if(i>=0)
            s.push(asteroids[i]);
        }
        
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};