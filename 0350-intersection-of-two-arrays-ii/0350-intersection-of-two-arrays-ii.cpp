class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>freq;
        vector<int>result;
        for(int nums:nums1) freq[nums]++;
        for(int nums:nums2){
            if(freq[nums]>0) result.push_back(nums);
            freq[nums]--;
        }
        return result;
    }
};