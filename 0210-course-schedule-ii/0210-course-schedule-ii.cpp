class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto& pre: prerequisites){
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int>q;
        for(int i=0; i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int>order;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            order.push_back(course);
            for(int neighbor: adj[course]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) q.push(neighbor);
            }
        }
        if(order.size() == numCourses) return order;
        else return {};
    }
};