class Solution {
public:
    string countAndSay(int n) {
        string ans="1", dummy;

        n--;
        while(n--)
        {
            int i=0, x=1, j=0;
            while(i<ans.size()-1)
            {
                if(ans[i]==ans[i+1])
                {
                    x++;
                    i++;
                    continue;
                }
                else
                {
                    dummy.push_back(x+48);
                    dummy.push_back(ans[i]);
                    x=1;
                    i++;
                }
                
            }

            dummy.push_back(x+48);
            dummy.push_back(ans[i]);
            ans.erase();
            
            for(int i=0;i<dummy.size();i++)
            {
                ans.push_back(dummy[i]);
            }
            
            dummy.erase();
        }    
        
        return ans;
    }
};