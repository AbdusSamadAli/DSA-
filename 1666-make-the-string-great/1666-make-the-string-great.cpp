class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(char ch:s){
            if(!st.empty() && abs(st.top()- ch)== 32) st.pop();
            else st.push(ch);
                
        }
        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};