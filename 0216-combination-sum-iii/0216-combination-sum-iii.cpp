class Solution {
public:
    void backtrack(int start, int k, int n,vector<int>& subset, vector<vector<int>>& result){
         if(k==0 && n==0){
            result.push_back(subset);
            return;
        }
        if(k==0 || n<0) return;
        for(int i=start; i<=9;i++){
            subset.push_back(i);
            backtrack(i+1, k-1, n-i, subset, result);
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subset;
        vector<vector<int>> result;
        backtrack(1,k,n,subset, result);
        return result;
    }
};