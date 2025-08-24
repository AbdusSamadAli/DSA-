class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int time  = 0;
        int prevmax = 0;
        for(int i=0;i<n;i++){
            if(i>0 && colors[i]!=colors[i-1]) prevmax  = 0;
            time+= min(prevmax,neededTime[i]);
            prevmax = max(prevmax, neededTime[i]);
        }
        return time;
    }
};