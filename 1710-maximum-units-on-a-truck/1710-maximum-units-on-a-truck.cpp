class Solution {
public:
    static bool sortcol(const vector<int> &v1, const vector<int> &v2)
    {
        return v1[1] > v2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), sortcol);
        int cnt=0;
        
        for(int i=0;i<boxTypes.size() && truckSize;i++)
        {
            cnt+=boxTypes[i][1]*(min(truckSize, boxTypes[i][0]));
            truckSize-=min(truckSize, boxTypes[i][0]);
        }
        
        return cnt;
    }
};