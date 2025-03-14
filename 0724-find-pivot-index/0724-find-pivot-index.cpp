class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalsum=0, leftsum=0;
        for(int n:nums) totalsum = totalsum + n;
        for(int i=0;i<nums.size();i++){
            if(leftsum == totalsum - leftsum - nums[i])
                 return i; //checks if the left sum is equal to the right sum at index i.
            leftsum = leftsum + nums[i];
        }
        return -1;
    }
};
//Prefix sum concept
//rightSum=totalSum−leftSum−nums[i]