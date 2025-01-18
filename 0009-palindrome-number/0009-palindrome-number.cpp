class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int orig=x; // Store the original value of x
        long rev=0; //Initialize a variable to store the reversed number
        while(x>0){
            int rem=x%10; // Get the last digit of x
            rev=rev*10+rem; // Append the digit to the reversed number
            x/=10; // Remove the last digit from x
        }
        return orig==rev;
    }
};

//First iteration: x = 121, rem = 1 (last digit). So, rev = 0 * 10 + 1 = 1, and x = 12.
//Second iteration: x = 12, rem = 2 (last digit). So, rev = 1 * 10 + 2 = 12, and x = 1.
//Third iteration: x = 1, rem = 1 (last digit). So, rev = 12 * 10 + 1 = 121, and x = 0.