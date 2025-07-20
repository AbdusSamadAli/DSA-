class Solution {
public:
    vector<string>result;
    void backtrack(string current, int open, int close, int n){
        if(current.length() == n*2){
            result.push_back(current);
            return;
        }
        if(open<n){
            backtrack(current + '(', open+1,close,n);
        }
        if(close<open){
            backtrack(current + ')', open, close+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        string current;
        backtrack(current,0,0,n);
        return result;
    }
};