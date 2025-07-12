class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return solve(i,s);
    }
    int solve(int &i, string &s){
        int num = 0, result = 0;
        int sign = 1;
        while(i<s.size()){
            char c = s[i];
            if(isdigit(c)) num = num*10 + (c - '0');
            else if(c == '+'){
                result = result + sign*num;
                num = 0;
                sign = 1;
            }
            else if(c == '-'){
                result = result + sign*num;
                num = 0;
                sign = -1;
            }
            else if(c == '('){
                i++;
                num = solve(i,s);
            }
            else if(c ==')'){
                result = result + sign * num;
                return result;
            }
            i++;
        }
        result = result + sign*num;
        return result;
    }
};