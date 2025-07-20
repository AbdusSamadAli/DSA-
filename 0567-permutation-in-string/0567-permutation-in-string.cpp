#include <unordered_map>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size()>s2.size()){
             return false;
        }
        std::unordered_map<char,int>count;
        for(char c:s1){
            count[c]++;

        }
        int l=0,r=0,req=s1.size();
        while(r<s2.size()){
            if(count[s2[r++]]-- >0){
                req--;
            }
            if(req==0){
                return true;
            }
            if(r-l==s1.size()&& count[s2[l++]]++>=0){
                req++;
            }
        }
        return false;
    }
};