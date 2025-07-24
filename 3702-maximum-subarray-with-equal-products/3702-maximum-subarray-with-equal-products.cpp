class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0;
        for(int left=0;left<n;left++){
            long long product = 1;
            int gcdval = nums[left];
            int lcmval = nums[left];
            for(int right=left;right<n;right++){
                if(product> 1e18/(nums[right])) break;
                product = product * nums[right];
                gcdval = gcd(gcdval,nums[right]);
                lcmval = lcm(lcmval,nums[right]);
                if(product == 1LL*gcdval*lcmval) maxlen = max(maxlen,right-left+1);
            }
        }
        return maxlen;
    }
};