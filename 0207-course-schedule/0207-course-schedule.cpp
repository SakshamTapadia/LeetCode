class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& pre) {

        unordered_map<int,vector<int>>adj;
        vector<int>indegree(V, 0);

        for(auto x: pre){
            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int>q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int>nodes;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            nodes.push_back(x);

            for(auto padosi: adj[x]){

                indegree[padosi]--;

                if(indegree[padosi] == 0) q.push(padosi);
            }
        }

        return nodes.size() == V;

        
    }
};