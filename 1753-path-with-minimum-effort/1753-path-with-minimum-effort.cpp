class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>>effort(n, vector<int>(m, INT_MAX));
        effort[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<>>pq;
        pq.push({0,0,0});
        vector<pair<int,int>>directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            int curreffort = curr[0];
            int x = curr[1];
            int y = curr[2];
            if(x==n-1 && y== m-1) return curreffort;
            for(auto[dx,dy]: directions){
                int nx = x+dx, ny = y+dy;
                if(nx>=0 && ny>=0 && ny<m && nx<n){
                    int diff = abs(heights[x][y] - heights[nx][ny]);
                    int maxeffort = max(curreffort, diff);
                    if(maxeffort < effort[nx][ny]){
                        effort[nx][ny] = maxeffort ;
                        pq.push({maxeffort, nx, ny});

                    }
                }
            }
        }
        return -1;
    }
};