class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string>bannedset(banned.begin(), banned.end());
        unordered_map<string,int>m;
        for(char& ch:paragraph){
            if(ispunct(ch)) ch = ' ';
            else ch = tolower(ch);
        }
        istringstream wordstream(paragraph);
        string word;
        while(wordstream>>word){
            if(bannedset.find(word) == bannedset.end()) m[word]++;
        }
        string result;
        int maxcount = 0;
        for(auto& [w,count] : m){
            if(count>maxcount){
                maxcount = count;
                result = w;
            }
        }
        return result;
    }
};