class Solution {
public:
    void backtrack(vector<int>& candidates,int target, int start, vector<int>&subset, vector<vector<int>>& result){
         if(target==0){ 
            result.push_back(subset);
            return;
        }
        for(int i=start; i < candidates.size(); i++){
            if(i> start && candidates[i]== candidates[i-1]) continue;
            if(candidates[i] > target) break;
            subset.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i+1, subset, result);
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>subset;
        vector<vector<int>>result;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, subset, result);
        return result;
    }
};