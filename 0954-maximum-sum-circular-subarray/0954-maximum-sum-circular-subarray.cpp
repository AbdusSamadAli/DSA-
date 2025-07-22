class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int totalsum=0, currmin = 0, currmax = 0;
        int maxsum = INT_MIN;
        int minsum = INT_MAX;
        for(int i=0;i<n;i++){
            totalsum = totalsum + nums[i];
            currmax = max(nums[i], currmax + nums[i]);
            currmin = min(nums[i], currmin + nums[i]);
            maxsum = max(currmax,maxsum);
            minsum = min(currmin,minsum);
        }
        if(maxsum<0) return maxsum;
        return max(maxsum, totalsum-minsum);
    }
};