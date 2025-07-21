class Solution {
public:
    string makeFancyString(string s) {
        string output;
        output.push_back(s[0]);
        int count = 1;
        for(int i=1;i<s.size();i++){
            char curr = s[i];
            char prev = s[i-1];
            if(curr == prev) count++;
            else count = 1;
            if(count>2) continue;
            output.push_back(curr);
        }
        return output;
    }
};