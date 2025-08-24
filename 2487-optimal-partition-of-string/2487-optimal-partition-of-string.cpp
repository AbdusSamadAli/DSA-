class Solution {
public:
    int partitionString(string s) {
        int count = 0;
        vector<int> seen(26,-1);
        int start = 0;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(seen[ch - 'a'] >= start){
                count++;
                start = i;
            }
            seen[ch - 'a'] = i;
        }
        return count+1;
    }
};