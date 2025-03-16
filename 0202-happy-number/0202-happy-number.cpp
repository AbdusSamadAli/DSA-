class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>set;
        while(n!=1){
            int sum = 0, temp = n;
            while(temp>0){
                int digit = temp % 10; //extract last digit
                sum = sum + digit*digit;
                temp = temp/10; //remove last digit
            }
            if(set.count(sum)) return false; //cycle detected
            set.insert(sum); //add new number to set
            n = sum; //update n to continue process
        }
        return true;
    }
};