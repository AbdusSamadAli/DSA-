class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(n<0) {
            x = 1/x;
            N=-N;
        }
        return powhelper(x,N);
    }
    double powhelper(double x,long long n){
        if(n==0) return 1.0;
        if(n==1) return x;
        double half = powhelper(x,n/2);
        if(n%2==0){
            return half * half;
        }
        else{
            return half * half * x;
        }
    }    
};