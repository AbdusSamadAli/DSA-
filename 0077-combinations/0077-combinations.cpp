class Solution {
public:
    void backtrack(vector<vector<int>>&v, vector<int>&temp,int n, int k, int index){
        if(temp.size()==k){
            v.push_back(temp);
            return;
        } 
        for(int i=index; i<=n;i++){
            temp.push_back(i);
            backtrack(v,temp,n,k,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>v;
        vector<int>temp;
        backtrack(v,temp,n,k,1);
        return v;
    }
};