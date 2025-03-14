
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int n:nums) m[n]++; //Count frequencies using hashmap
        int n = nums.size();
        vector<vector<int>>bucket(n+1); //create bucket array
        for(auto [num, freq]: m) bucket[freq].push_back(num); // Store elements in bucket of frequency
        vector<int>result;
        for(int i=n; i>=0 && result.size()<k;i--){ //get top k elements
            for(int num : bucket[i]){
                result.push_back(num);
                if(result.size() == k) return result; //stop once k elements are found
            } 
        }
        return result;
    }
};

//Use Bucket Sort when K is small or when maximum frequency is O(N)