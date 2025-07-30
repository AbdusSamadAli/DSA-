class Solution {
public:
    string toHex(int num) {
        unsigned int n = static_cast<unsigned int>(num);
        if(n == 0) return "0";
        string hexa = "0123456789abcdef";
        string result;
        while(n>0){
            int remainder = n%16;
            result = hexa[remainder] + result;
            n = n/16;
        }
        return result;
    }
};