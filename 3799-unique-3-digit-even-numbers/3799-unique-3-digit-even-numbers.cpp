class Solution {
public:
    void solve(vector<int>& digits,string str,vector<bool> &used,unordered_set<int> &output){
        if(str.size() == 3){
            if((str[2]-'0') % 2 == 0) output.insert(stoi(str));
            return;
        }
        for(int i=0;i< digits.size();i++){
            if(used[i]) continue;
            if(str.empty() && digits[i] == 0) continue;
            used[i] = true;
            solve(digits, str + to_string(digits[i]), used, output);
            used[i] = false; //backtrack
        }
    }
    int totalNumbers(vector<int>& digits) {
        vector<bool> used(digits.size(), false);
        unordered_set<int>output;
        solve(digits, "", used, output);
        return output.size();
    }
};