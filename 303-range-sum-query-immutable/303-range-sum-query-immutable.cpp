class NumArray {
public:
    vector<int> arr, sums;
    NumArray(vector<int>& nums) {
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            arr.push_back(nums[i]);
            sum+=arr[i];
            sums.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return sums[right]-sums[left]+arr[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */