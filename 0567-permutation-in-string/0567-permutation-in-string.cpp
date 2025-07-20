class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int>s1count(26,0);
        vector<int>s2count(26,0);
        for(int i=0; i<s1.size();i++){
            s1count[s1[i] -'a']++;
            s2count[s2[i] -'a']++;
        }
        int matches = 0;
        for(int i=0; i<26;i++) matches = matches + (s1count[i]==s2count[i]);
        for(int right=s1.size(), left=0; right<s2.size();right++,left++ ){
            if(matches == 26) return true;
            int index1 = s2[right] - 'a', index2 = s2[left] - 'a';
            s2count[index1]++;
            if(s1count[index1] == s2count[index1]) matches++;
            else if(s2count[index1]-1 == s1count[index1]) matches--;
            s2count[index2]--;
            if(s1count[index2] == s2count[index2]) matches++;
            else if(s2count[index2]+1 == s1count[index2]) matches--;
        }
        return matches == 26;
    }
};