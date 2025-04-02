class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>result;
        unordered_map<int,bool >seen;
        for(int num:nums) seen[num] = true; 
        for(int i=1; i<=n;i++){
            if(!seen[i]) result.push_back(i);
        }
        return result;
    }
};