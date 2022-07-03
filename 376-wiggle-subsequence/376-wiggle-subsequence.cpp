class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
       /* if(nums.size()==1)
            return 1;
        else if(nums.size()==2)
        {
            if(nums[0]!=nums[1])
                return 2;
            else
                return 1;
        }  */
        
        vector<int> hash;
        
        for(int i=1;i<nums.size();i++)
        {
            if((nums[i]-nums[i-1])!=0)
                hash.push_back(nums[i]-nums[i-1]);
        }
        
        int i=1;
        while(i<hash.size())
        {
            if((hash[i]>0 && hash[i-1]<0) || (hash[i]<0 && hash[i-1]>0))
                i++;
            else
                hash.erase(hash.begin()+i);
            
        }
        
        return hash.size()+1;
    }
};