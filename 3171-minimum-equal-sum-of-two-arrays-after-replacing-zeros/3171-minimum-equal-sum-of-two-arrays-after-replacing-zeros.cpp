class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0, nums1zero = 0, nums2zero = 0;
        for(int &n: nums1){
            sum1+=n;
            if(n==0){
                nums1zero++;
                sum1++;
            } 
        }
        for(int &n: nums2){
            sum2+=n;
            if(n==0) {
                nums2zero++;
                sum2++;
            }
        }
        if(sum2 > sum1 && nums1zero == 0) return -1;
        if(sum2 < sum1 && nums2zero == 0) return -1;
        return max(sum1,sum2);
    }
};