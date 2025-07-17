class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>sorted = nums;
        sort(sorted.begin(), sorted.end());
        unordered_map<int,int>m;
        for(int i=0;i<sorted.size();i++){
            if(m.find(sorted[i]) == m.end()) m[sorted[i]] = i;
        }
        vector<int>output;
        for(int n:nums){
            output.push_back(m[n]);
        }
        return output;
    }
};
/*
 vector<int>output(nums.size(), 0);
        for(int i=0;i<nums.size();i++){
            for(int j=0; j<nums.size(); j++){
                if(nums[j]<nums[i]) output[i]++;
            }
        }
        return output;
*/