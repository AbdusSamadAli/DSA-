class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string result;
        string temp;
        int n = path.length();
        for(int i=0;i<n;i++){
            if(path[i] == '/') continue;
            temp.clear();
            while(i<n && path[i] != '/'){
                temp = temp + path[i];
                i++;
            }
            if(temp == ".") continue;
            else if(temp == ".."){
                if(!st.empty()) st.pop();
            }
            else st.push(temp);
        }
        while(!st.empty()){
            result = '/' + st.top() + result;
            st.pop();
        }
        if(result.empty()){
            return "/";
        }
        else return result;
    }
};