class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        for(char ch:s){
            if(isdigit(ch)){
                if(!st.empty() && !isdigit(st.top())) st.pop();
            }
             else st.push(ch);
        }
        string result="";
        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};