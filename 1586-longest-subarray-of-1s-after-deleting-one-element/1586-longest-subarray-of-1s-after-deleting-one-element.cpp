class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0, zerocount=0, maxlen=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==0) zerocount++;
            while(zerocount>1){
                if(nums[left]==0) zerocount--;
                left++;
            }
            maxlen = max(maxlen,right-left);
        }
        return maxlen;
    }
};