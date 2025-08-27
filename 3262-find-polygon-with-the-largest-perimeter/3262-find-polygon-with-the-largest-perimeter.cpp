class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
       sort(nums.begin(), nums.end(), greater<>());
       long long sum = 0;
       for(int i:nums) sum+=i;
       int n = nums.size();
       for(int i=0;i<n;i++){
        long long remainingsum = sum - nums[i];
        if(remainingsum > nums[i]) return sum;
        else sum = sum - nums[i];
       }
       return -1;
    }
};