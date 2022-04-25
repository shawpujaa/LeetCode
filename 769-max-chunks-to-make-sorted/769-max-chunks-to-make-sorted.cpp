class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size(), count=0, maxnum=-1, first=-1;
        
        for(int i=0;i<n;i++)
        {
            maxnum=max(arr[i], maxnum);
            
            if(arr[i]<=i && i>=maxnum)
                count++;
        }
        
        return count;
    }
};