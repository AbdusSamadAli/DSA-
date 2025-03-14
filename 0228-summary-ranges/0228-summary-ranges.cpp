class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>result;
        int n = nums.size();
        if(n==0) return result;
        int left = 0; //start of current range
        for(int right=1; right<=n;right++){ //right<=n ensures last range is processed
            if(right == n || nums[right]!= nums[right-1]+1){
                if(left == right -1) result.push_back(to_string(nums[left])); //single number case
                else result.push_back(to_string(nums[left]) + "->" + to_string(nums[right-1]));
                left = right; //move left pointer to new range start
            }
        }
        return result;
    }
};
//two pointer approach
//consecutive means:nums[right] == nums[right - 1] + 1
