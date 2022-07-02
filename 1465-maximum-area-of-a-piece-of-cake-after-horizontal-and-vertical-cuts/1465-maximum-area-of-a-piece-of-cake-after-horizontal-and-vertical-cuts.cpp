class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long mod=1000000007, height=0, width=0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        height=horizontalCuts[0];
        width=verticalCuts[0];
        
        for(int i=1;i<horizontalCuts.size();i++)
        {
            if(height < horizontalCuts[i]-horizontalCuts[i-1])
                height=horizontalCuts[i]-horizontalCuts[i-1];
        }
        
        for(int i=1;i<verticalCuts.size();i++)
        {
            if(width < verticalCuts[i]-verticalCuts[i-1])
                width=verticalCuts[i]-verticalCuts[i-1];
        }
        
        if(height < h-horizontalCuts[horizontalCuts.size()-1])
            height=h-horizontalCuts[horizontalCuts.size()-1];
        
        if(width < w-verticalCuts[verticalCuts.size()-1])
        width=w-verticalCuts[verticalCuts.size()-1];
        
        height%=mod;
        width%=mod;
        cout<<height<<" "<<width;
        return (height*width)%mod;
    }
};