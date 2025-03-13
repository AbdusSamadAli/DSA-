class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int n = nums.size();
      int currsum=0;
      int start=0;
      int minlength = INT_MAX;
      for(int end=0;end<n;end++){
        currsum+=nums[end];
        while(currsum>=target){
            minlength = min(minlength, end-start+1);
            currsum =  currsum-nums[start]; //shrink window when sum>=target so all valid min length subarrays can be found
            start++;
        }
      }
      if(minlength == INT_MAX) return 0;
      else{
        return minlength;
      }
    }
};