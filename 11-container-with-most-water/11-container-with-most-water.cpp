class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        
        for(int i=0, j=height.size()-1; i<j ; )
        {
            ans=max((j-i)*min(height[i], height[j]), ans);
            
            if(height[i]>height[j])
                j--;
            else 
                i++;
        }
        
        return ans;
    }
};