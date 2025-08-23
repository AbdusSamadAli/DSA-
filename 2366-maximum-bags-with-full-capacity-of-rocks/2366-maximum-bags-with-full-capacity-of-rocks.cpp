class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int>need(n,0);
        for(int i=0;i<n;i++){
            int rock = rocks[i];
            int c = capacity[i];
            int neededrocks = c - rock;
            need[i] = neededrocks;
        }
        sort(need.begin(),need.end());
        int count = 0;
        for(int i=0;i<n;i++){
            if(need[i] == 0) count++;
            else{
                if(additionalRocks >= need[i]){
                    additionalRocks  = additionalRocks - need[i];
                    count++;
                }
                else break;
            }
        }
        return count;
    }
};