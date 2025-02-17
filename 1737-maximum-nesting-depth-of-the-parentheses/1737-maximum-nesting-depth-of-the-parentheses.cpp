class Solution {
public:
    int maxDepth(string s) {
        int currentdepth=0, maxdepth=0;
        for(char c:s){
            if(c=='('){
                currentdepth++;
                maxdepth = max(maxdepth, currentdepth);
            }
            else if(c==')'){
                currentdepth--;
            }
        }
        return maxdepth;
    }
};