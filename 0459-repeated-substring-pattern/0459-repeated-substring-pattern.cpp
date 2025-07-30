class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size()<2) return false;
        int n = s.size();
        for(int i=1;i<=n/2;i++){
            if(n%i==0){
                string pattern = s.substr(0,i);
                string repeated = "";
                for(int j=0;j<n/i;j++){
                    repeated = repeated + pattern;
                    if(repeated == s) return true;
                }
            }
        }
        return false;
    }
};