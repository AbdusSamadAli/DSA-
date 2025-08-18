class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.size() <2) return "";
        string result = "";
        for(int i=0;i<s.size();i++){
            int lowermask=0, uppermask = 0;
            for(int j=i;j<s.size();j++){
                if(islower(s[j])) lowermask |= (1<<(s[j] -'a'));
                else uppermask |= (1<<(s[j] - 'A'));
                if((lowermask^uppermask) == 0){
                    if(j-i+1 > result.size()) result = s.substr(i,j-i+1);
                }
            }
        }
        return result;
    }
};