class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string l = s + '#' + rev;
        vector<int>lps(l.size(), 0);
        for(int i=1; i<l.size();i++){
            int len = lps[i-1];
            while(len>0 && l[i]!=l[len]) len = lps[len-1];
            if(l[i] == l[len]) len++;
            lps[i] = len;
        }
        string suffix = s.substr(lps.back());
        reverse(suffix.begin(), suffix.end());
        return suffix + s;
    }
};