class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>dist(m, vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        int directions[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty()){
            auto[row, col] = q.front();
            q.pop();
            for(auto d:directions){
                int newrow = row + d[0], newcol = col + d[1];
                if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && dist[newrow][newcol]==-1){
                    dist[newrow][newcol] = dist[row][col] + 1;
                    q.push({newrow, newcol});
                }
            }
        }
        return dist;       
    }
};