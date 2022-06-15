class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool flag=1;
        int i=0;
        
        while(i<nums.size() && nums[i]+i<nums.size()-1)
        {
            
            int j=i+1;
            int idx=i;
            
            while(j<nums.size() && (nums[i]+i)>=j)
            {
                if(nums[idx]+idx<(nums[j]+j))
                    idx=j;
                
                j++;
            }
          //  cout<<i<<" "<<idx<<"\n";
            if(idx==i)
            {
                flag=0;
                break;
            }
            i=idx;
            
        }
        
        return flag;
    }
};