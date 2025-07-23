class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        vector<int>m1(26,0); 
        vector<int>m2(26,0);
        vector<bool>exist1(26,false);
        vector<bool>exist2(26,false);
        for(char c:word1){
            m1[c-'a']++;
            exist1[c-'a'] = true;
        }
        for(char c:word2){
            m2[c-'a']++;
            exist2[c-'a']= true;
        }
        if(exist1 != exist2) return false;
        sort(m1.begin(), m1.end());
        sort(m2.begin(), m2.end());
        return m1==m2;
    }
};
