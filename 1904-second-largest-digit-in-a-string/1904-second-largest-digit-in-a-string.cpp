class Solution {
public:
    int secondHighest(string s) {
       set<int>digits;
       for(char ch:s){
        if(isdigit(ch)) digits.insert(ch-'0');
       }
       if(digits.size()<2) return -1;
       auto it = digits.rbegin();
       it++;
       return *it;
    }
};