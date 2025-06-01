class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int>dp(nums.size(), 1), count(nums.size(),1);
        int maxlen = 1;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]> nums[j]){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if(dp[j]+1 == dp[i]) count[i] = count[i] + count[j];
                }
            }
            maxlen = max(maxlen, dp[i]);
        }
        int result = 0;
        for(int i=0;i<nums.size(); i++){
            if(dp[i] == maxlen) result = result + count[i];
        }
        return result;
    }
};