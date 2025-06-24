class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1,vector<int>& nums2,vector<int>& nums3) {
        unordered_map<int,int>m;
        unordered_set<int>s1(nums1.begin(), nums1.end());
        unordered_set<int>s2(nums2.begin(), nums2.end());
        unordered_set<int>s3(nums3.begin(), nums3.end());
        for(int n:s1) m[n]++;
        for(int n:s2) m[n]++;
        for(int n:s3) m[n]++;
        vector<int>output;
        for(auto& [num,freq]: m){
            if(freq>=2) output.push_back(num);
        }
        return output;
    }
};