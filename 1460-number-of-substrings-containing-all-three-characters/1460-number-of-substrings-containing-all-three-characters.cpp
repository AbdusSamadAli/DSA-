class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0,right=0, result=0, n= s.size();
        unordered_map<char,int>m;
        for(right=0; right<n;right++){
            m[s[right]]++;
            while(m['a']>0 && m['b']> 0 && m['c']>0){
                result+= (n-right);
                m[s[left]]--;
                left++;
            }
        }
        return result;
    }
};