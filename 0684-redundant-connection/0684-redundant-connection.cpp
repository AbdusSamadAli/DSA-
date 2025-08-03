class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>&visited){
        visited[node] = true;
        for(int neighbor: graph[node]){
            if(!visited[neighbor]){
                if(dfs(neighbor,node,graph,visited)) return true;
            }
            else if(neighbor!=parent) return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>graph(n+1);
        for(auto& edge:edges){
            int u = edge[0], v = edge[1];
            vector<bool>visited(n+1,false);
            graph[u].push_back(v);
            graph[v].push_back(u);
            if(dfs(u,-1,graph,visited)) return edge;
        }
        return {};
    }
};