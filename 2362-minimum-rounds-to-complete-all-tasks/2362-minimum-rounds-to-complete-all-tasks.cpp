class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
     sort(tasks.begin(),tasks.end());
     int n = tasks.size();
     int rounds = 0;
     unordered_map<int,int>m;
     for(int t:tasks) m[t]++;
     for(auto& p:m){
        if(p.second == 1) return -1;
        if(p.second %3 == 0) rounds += p.second/3;
        else rounds += p.second/3 + 1;
     }
     return rounds;
    }
};