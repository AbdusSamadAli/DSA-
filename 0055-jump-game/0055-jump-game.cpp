class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goal = 0; // Tracks the farthest reachable index
        for(int i= 0; i<n;i++){
            if(i>goal) return false; // If i is beyond our reachable range, return false
            goal = max(goal, i+nums[i]); // Update the farthest we can gp
        }
        return true; // If we reach here, we can reach the last index
    }
};

//greedy approach
//1️⃣ Solve Jump Game II (Min Jumps to End) to reinforce this logic.
//2️⃣ Solve Can Place Flowers for another easy Greedy problem.
// 3)  Gas Station (Circular Jumping, Similar Concept)
// 4) Farthest Building You Can Reach (Greedy Heap Approach)