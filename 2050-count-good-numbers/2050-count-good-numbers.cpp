class Solution {
public:
    const int MOD = 1e9 + 7;
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        if (n == 0) return 1;
        if (n % 2 == 0) {
            long long evenPart = modPow(5, n / 2, MOD);
            long long oddPart = modPow(4, n / 2, MOD);
            return (evenPart * oddPart) % MOD;
        }
        else {
            long long evenPart = modPow(5, n / 2 + 1, MOD);
            long long oddPart = modPow(4, n / 2, MOD);
            return (evenPart * oddPart) % MOD;
        }
    }
};
