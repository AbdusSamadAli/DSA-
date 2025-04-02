class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return *max_element(nums.begin(), nums.end());
        sort(nums.begin(), nums.end(), greater<int>());
        int distinct = 1;
        for(int i=1; i<n;i++){
            if(nums[i]!= nums[i-1]) distinct++;
            if(distinct == 3) return nums[i];
        }
        return nums[0];
    }
};