class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0, right=0, maxlen=0;
        for(right=0; right<nums.size();right++){
            if(nums[right]==0) k--;
            while(k<0){
                if(nums[left]==0) k++;
                left++;
            }
            maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
    }
};