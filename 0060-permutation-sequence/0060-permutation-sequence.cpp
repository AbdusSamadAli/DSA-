class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>nums;
        for(int i=1;i<=n;i++) nums.push_back(i);
        int fact = 1;
        for(int i=1;i<n;i++) fact = fact * i;
        k--;
        string output = "";
        while(!nums.empty()){
            int index = k / fact;
            output = output + to_string(nums[index]);
            nums.erase(nums.begin() + index);
            if(nums.empty()) break;
            k = k % fact;
            fact = fact / nums.size();
        }
        return output;
    }
};