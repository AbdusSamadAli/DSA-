class Solution {
public:
    int xorOperation(int n, int start) {
        int xorvalue=0;
        vector<int>nums(n,start);
        for(int i=0;i<n;i++){
            int val = start+2*i;
            xorvalue ^= val;
        }
        return xorvalue;
    }
};