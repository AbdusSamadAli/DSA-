class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int result = 0;
        int n = arrays.size();
        int MIN = arrays[0].front();
        int MAX = arrays[0].back();
        for(int i=1;i<n;i++){
            int currmin = arrays[i].front();
            int currmax = arrays[i].back();
            result = max({result, abs(currmin - MAX),abs(currmax - MIN)});
            MAX = max(MAX, currmax);
            MIN = min(MIN, currmin);
        }
        return result;
    }
};