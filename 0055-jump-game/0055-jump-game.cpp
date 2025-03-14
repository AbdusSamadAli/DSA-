class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool>dp(n,false);  // Base case: Last index is always reachable
        dp[n-1] = true;
        for(int i= n-2; i>=0; i--){ 
            int maxjump = min(nums[i]+i, n-1);  // Find the farthest we can jump
            for(int j=i+1; j<=maxjump; j++){
                if(dp[j]){
                    dp[i] = true; 
                    break;
                } 
            }
        }
        return dp[0];
    }
};



//Pattern Name: "Reachability DP" + "Bottom-Up DP"
//"Can you reach a destination?" → Think DP or BFS.
//"Work backwards" → Try bottom-up DP.
//"Can I make the next move using previous decisions?" → Greedy Optimization.