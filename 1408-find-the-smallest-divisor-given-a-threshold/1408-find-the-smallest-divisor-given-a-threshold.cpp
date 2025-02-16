class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1, high = *max_element(nums.begin(), nums.end());
        while(low<high){
            int mid = (low+high)/2;
            int sum=0;
            for(int n:nums){
                sum+= ceil((double)n/mid);
            }
            if(sum > threshold){
                low = mid + 1 ;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
};