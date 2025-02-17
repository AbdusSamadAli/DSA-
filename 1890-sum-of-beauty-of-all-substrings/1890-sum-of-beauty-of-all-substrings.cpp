class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int beauty=0;
        for(int i=0;i<n;i++){ //starting substring
            unordered_map<char,int>m;
            for(int j=i;j<n;j++){ //ending substring
                m[s[j]]++;
                int minfrequency= INT_MAX, maxfrequency=0;
                for(auto& p:m){
                    maxfrequency = max(maxfrequency, p.second);
                    minfrequency = min(minfrequency, p.second);
                }
                beauty+= (maxfrequency - minfrequency);
            }
        }
        return beauty;
    }
};