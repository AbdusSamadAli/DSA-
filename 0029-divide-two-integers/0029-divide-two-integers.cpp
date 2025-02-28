class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor==-1) return INT_MAX;
         if(dividend == INT_MIN && divisor==1) return INT_MIN;
        bool isNegative = (divisor<0) ^ (dividend<0);
        long long num = (long long)dividend;
        long long den = (long long)divisor;
        num = llabs(num);
        den = llabs(den);
        int quotient=0;
        while(num>=den){
            long long temp = den, multiple=1;
            while((temp<<1)<=num){
                temp<<=1;
                multiple<<=1;
            }
            num-=temp;
            quotient+=multiple;
        }
        return isNegative ? -quotient : quotient;
    }
};