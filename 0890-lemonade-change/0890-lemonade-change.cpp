class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0, ten=0;
        for(int bill:bills){
            if(bill==5) five++;
            else if(bill==10){
                if(five>0){
                    five--;
                    ten++;
                }
                else{
                    return false;
                }
            }
            else{
                if(ten>0 && five>0){
                    ten--;
                    five--;
                }
                else if(five>=3) five-=3;
                else return false;
            }
        }
        return true;
    }
};
//greedy approach:
//Prioritizing $10 + $5 over $5 + $5 + $5 ensures we keep smaller bills available.
//If a customer pays with $20, and we only have $10 bills, 
//we must have at least one $5 bill to complete the transaction.