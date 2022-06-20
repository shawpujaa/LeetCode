class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n=arr.size();
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>arr[i+1])
            {
                int mx=arr[i+1], idx=i+1;
                int j=i+2;
                while(j<n)
                {
                    if(arr[j]<arr[i] && mx<arr[j])
                    {
                        idx=j;
                        mx=arr[j];
                    }
                    j++;
                }
                swap(arr[i], arr[idx]);
                break;
            }
        }
        
        return arr;
    }
};