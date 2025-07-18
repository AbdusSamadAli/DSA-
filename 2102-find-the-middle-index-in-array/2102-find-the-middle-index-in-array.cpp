class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size(), leftsum  = 0;
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        for(int i=0;i<n;i++){
            int rightsum = totalsum - leftsum - nums[i];
            if(i == 0) leftsum = 0;
            if(i == n-1) rightsum = 0;
            int prefix = prefix + nums[i]; 
            if(leftsum == rightsum) return i;
            leftsum = leftsum + nums[i];
        }
        return -1;
    }
};