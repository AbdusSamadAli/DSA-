class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
     return fn(nums, 0,1,0,1,0,target);
    }
    bool fn(vector<int>& nums,int i, long long prod1,int size1, long long prod2, int size2, long long target){
        if(i == nums.size()){
            return size1> 0 && size2>0  && prod1 == target && prod2 == target;
        }
        if(prod1> target || prod2> target) return false;
        if(fn(nums, i+1, prod1*nums[i], size1+1, prod2, size2, target)) return true;
        if(fn(nums, i+1,prod1, size1, prod2*nums[i], size2+1, target)) return true;
        return false;
    }
};