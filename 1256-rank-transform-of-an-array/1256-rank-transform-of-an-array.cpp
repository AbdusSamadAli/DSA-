class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int rank  = 1;
        vector<int> output = arr;
        sort(output.begin(), output.end());
        unordered_map<int,int>m;
        for(int i:output){
            if(m.find(i) == m.end()) m[i] = rank++;
        }
        vector<int>result;
        for(int i:arr){
            result.push_back(m[i]);
        }
        return result;
    }
};