class Solution {
private:
    void solve(vector<int> nums, vector <int> output, int i,vector<vector <int>>&ans){
        if(i >= nums.size()){
            ans.push_back(output);
            return ;
        }
        solve(nums,output,i+1,ans);
        int element=nums[i];
        output.push_back(element); 
        solve(nums,output,i+1,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector <int>> ans;
        vector <int> output;
        int i=0;
        solve(nums,output,i,ans);
        return ans;
    }
};