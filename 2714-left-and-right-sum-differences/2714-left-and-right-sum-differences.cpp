class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>answer(n,0);
        int totalsum = accumulate(nums.begin(), nums.end(),0);
        int leftsum=0;
        for(int i=0;i<n;i++){
            int rightsum = totalsum - leftsum - nums[i];
            answer[i] = answer[i] + abs(leftsum - rightsum);
            leftsum = leftsum + nums[i];
        }
        return answer;
    }
};