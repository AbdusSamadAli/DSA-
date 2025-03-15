class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxheight = 0, currheight =0;
        for(int i=0; i<gain.size(); i++){
            currheight = currheight + gain[i];
            maxheight = max(maxheight, currheight);
        }
        return maxheight;
    }
};