class Solution {
public:
    static bool compare(string a, string b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
       vector<string> largest;
       for(int i:nums) largest.push_back(to_string(i));
       sort(largest.begin(), largest.end(), compare);
       if(largest[0] == "0") return "0";
       string result = "";
       for(string s:largest) result+=s;
       return result;
    }
};