class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>globalFreq(26, INT_MAX);
        for (string word : words) {  
            vector<int>m(26,0);
            for (char ch : word) {  
                m[ch-'a']++;
            }
            for(int i=0; i<26;i++){
                globalFreq[i] = min(globalFreq[i],m[i]);
            }
        }
       vector<string>result;
        for(int i=0; i<26; i++){
            while(globalFreq[i]>0){
                result.push_back(string(1, i + 'a'));
                globalFreq[i]--;
            }
        }
        return result;
    }
};