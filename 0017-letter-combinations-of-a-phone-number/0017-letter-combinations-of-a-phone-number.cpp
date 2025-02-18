class Solution {
public:
    void backtrack(string& digits, int index, string& combination, vector<string>& result, unordered_map<char,string>&m ){
        if(index == digits.size()){
            result.push_back(combination);
            return;
        }
        char digit = digits[index];
        string letters  = m[digit];
        for(char letter: letters){
            combination.push_back(letter);
            backtrack(digits, index+1, combination, result, m);
            combination.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char,string>m ={
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string>result;
        string combination;
        backtrack(digits, 0, combination, result, m);
        return result;
    }
};