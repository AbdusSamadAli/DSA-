class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char,int>m;
        for(char c:s){
            m[c]++;
        }
        for(char c:t){
            if(m.find(c)== m.end() || m[c]==0){
                return false;
            }
            m[c]--;
        }
        return true;
    }
};