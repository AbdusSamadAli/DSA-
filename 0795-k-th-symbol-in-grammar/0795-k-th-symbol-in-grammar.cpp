class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        int mid = pow(2,n-1) / 2;
        if(k<=mid) return kthGrammar(n-1,k); //left half is same as previous row i.e n-1
        else return 1 - kthGrammar(n-1, k-mid); //right half is flip of previous row so 1 - fn
    }
};
//Length of row = 2^n-1, so mid length = 2^n-1/2 i.e pow(2,n-1)/2