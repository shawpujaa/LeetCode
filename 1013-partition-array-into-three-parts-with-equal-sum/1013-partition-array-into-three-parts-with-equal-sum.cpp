class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0, leftSum=arr[0], rightSum=arr[arr.size()-1];
        
        for(int i=0;i<arr.size();i++)
            sum+=arr[i];
        
        if(sum%3)
            return false;
        sum/=3;
        
        for(int i=0, j=arr.size()-1;i+1<j;)
        {
            if(sum==rightSum && leftSum==sum)
                return true;
            
            if(leftSum!=sum)
            {
                i++;
                leftSum+=arr[i];
            }
            
            if(rightSum!=sum)
            {
                j--;
                rightSum+=arr[j];
            }
        }
        
        return false;
    }
};