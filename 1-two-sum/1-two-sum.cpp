class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int size=nums.size();
        vector< pair<int, int> > array;
        vector<int> ans;
        
        for(int i=0;i<size;i++)
            array.push_back(make_pair(nums[i], i));
        
        sort(array.begin(), array.end());
        
        for(int i=0, j=size-1; i<j;)
        {
            if(array[j].first>(target-array[i].first))
                j--;
            else if((array[i].first+array[j].first)==target)
            {
                ans.push_back(array[i].second);
                ans.push_back(array[j].second);
                break;
            }
            else
            {
                i++;
            }
        }
        
        return ans;
    }
};