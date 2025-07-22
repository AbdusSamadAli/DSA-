class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
     int n = grid.size();
     map<vector<int>,int>m;
     int count=0;
     for(int i=0;i<n;i++) m[grid[i]]++;
     for(int j=0;j<n;j++){
        vector<int>col;
        for(int i=0;i<n;i++) col.push_back(grid[i][j]);
        if(m.find(col)!=m.end()) count = count + m[col];
     }
     return count;
    }
};