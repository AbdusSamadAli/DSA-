class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int s=0,e=nums.size()-1;
        while(s<e){
            int mid = s+(e-s)/2;
            if((mid==0 || nums[mid]!=nums[mid-1]) && 
            (mid==nums.size()-1 || nums[mid]!=nums[mid+1])){
               return nums[mid];
            }
            if(mid%2==1) mid--;
            if(nums[mid]==nums[mid+1]){
                s = mid+2;
            }
            else{
                e = mid;
            }
        }
        return nums[s];  
    }
};