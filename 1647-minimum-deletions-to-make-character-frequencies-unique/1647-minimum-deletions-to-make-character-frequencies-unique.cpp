class Solution {
public:
    int minDeletions(string s) {
        int hash[26]={0}, deletions=0, mx;
        
        for(int i=0;i<s.size();i++)
        hash[s[i]-97]+=1;
        
        sort(hash, hash+26);
        deletions=hash[25];
        mx=hash[25]-1;
        
        for(int i=24;i>=0;i--)
        {
            if(hash[i]==0 || mx==0)
                break;
            if(hash[i]<mx)
            {
                deletions+=hash[i];
                mx=hash[i]-1;
            }
            else
            {
                deletions+=mx;
                mx--;
            }
         
        }
        
        
        return s.size()-deletions;
    }
};