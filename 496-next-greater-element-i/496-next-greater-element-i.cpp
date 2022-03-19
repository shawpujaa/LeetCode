class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int nextgreater[10000];
        
        stack<int> great;
        
        for(int i=0;i<nums2.size();i++)
        {
            while(!great.empty() && nums2[great.top()]<nums2[i])
            {
                nextgreater[nums2[great.top()]]=nums2[i];
                
                great.pop();
            }
            
            great.push(i);
        }
        
        while(!great.empty())
        {
            nextgreater[nums2[great.top()]]=-1;
            
            great.pop();
        }
        
        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(nextgreater[nums1[i]]);
        }
        
        
        return ans;
    }
};