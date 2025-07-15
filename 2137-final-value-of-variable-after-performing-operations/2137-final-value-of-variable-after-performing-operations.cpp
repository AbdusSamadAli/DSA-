class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X=0;
        for(string s:operations){
            if(s == "X++" || s == "++X") X = X+1;
            else if(s == "X--" || s == "--X") X=X-1;
        }
        return X;
    }
};