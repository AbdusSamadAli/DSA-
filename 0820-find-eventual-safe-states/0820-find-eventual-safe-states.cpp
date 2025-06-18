class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>reversegraph(n);
        vector<int>indegree(n,0);
        for(int u=0;u<n;u++){
            for(int v:graph[u]){
                reversegraph[v].push_back(u);
                indegree[u]++;
            }
        }
        queue<int>q;
        for(int i=0; i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int>safenodes;
        while(!q.empty()){
            int node = q.front(); q.pop();
            safenodes.push_back(node);
            for(int neighbor: reversegraph[node]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) q.push(neighbor);
            }
        }
        sort(safenodes.begin(), safenodes.end());
        return safenodes;
    }
};