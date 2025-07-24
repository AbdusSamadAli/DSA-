class Solution {
public:
    int next(int i,vector<int>& nums){
        int n = nums.size();
        return ((i+nums[i])%n+n) % n;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0) continue;
            int slow = i, fast = i;
            bool forward = nums[i]>0;
            while(true){
                slow = next(slow,nums);
                if((nums[slow]>0) != forward || nums[slow]== 0) break;
                fast = next(fast,nums);
                if((nums[fast]>0) != forward || nums[fast]== 0) break;
                fast = next(fast,nums);
                if((nums[fast]>0) != forward || nums[fast]== 0) break;
                if(slow == fast){
                    if(slow == next(slow,nums)) break;
                    return true;
                }
            }
            int j=i;
            while((nums[j]>0) == forward && nums[j]!=0){
                int temp = next(j,nums);
                nums[j] = 0;
                j=temp;
            }
        }
        return false;
    }
};