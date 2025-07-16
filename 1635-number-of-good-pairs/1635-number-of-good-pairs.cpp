class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        unordered_map<int,int>m;
        for(int i:nums){
            count = count + m[i];
            m[i]++;
        } 
        return count;
    }
};