class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0, high=arr.size()-1, mid, idx;
        
        while(low<=high)
        {
            mid=(low+high)/2;
            if(mid==0)
                mid+=1;
            
            if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid])
            {
                idx=mid;
                break;
            }
            
            if(arr[mid-1]>arr[mid])
                high=mid-1;
            
            if(arr[mid+1]>arr[mid])
                low=mid+1;
        }
        
        return idx;
    }
};