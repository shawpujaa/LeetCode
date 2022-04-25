class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int  count=0, maxnum=-1;
        
        for(int i=0;i<arr.size();i++)
        {
            maxnum=max(arr[i], maxnum);
            
            if(i==maxnum)
                count++;
        }
        
        return count;
    }
};