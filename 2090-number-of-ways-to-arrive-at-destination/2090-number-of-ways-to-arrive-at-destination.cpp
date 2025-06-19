class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9+7;
        vector<vector<pair<int,int>>> adj(n);
        for(auto& r:roads){
            int u = r[0], v = r[1], time = r[2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<>>pq;
        vector<long long>dist(n, LLONG_MAX);
        vector<int>ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            auto[currtime, u] = pq.top(); pq.pop();
            if(currtime>dist[u]) continue;
            for(auto[v,time]: adj[u]){
                long long totaltime = currtime + time;
                if(totaltime< dist[v]){
                    dist[v] = totaltime;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if(totaltime == dist[v]) 
                    ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
        return ways[n-1];
    }
};