class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj, vector<int>&vis, vector<int>inRecursion, vector<int>&ans, int u, bool &hasCycle){

        if(hasCycle) return;
        vis[u] = 1;
        inRecursion[u] = 1;

        for(auto padosi: adj[u]){

            if(!vis[padosi]){
                dfs(adj, vis, inRecursion, ans, padosi, hasCycle);
            }
            else if(inRecursion[padosi]){
                hasCycle = true;
                return;
            }
        }

        ans.push_back(u);
        inRecursion[u] = 0;
    }
    vector<int> findOrder(int V, vector<vector<int>>& edges) {

        unordered_map<int,vector<int>>adj;
        vector<int>ans;
        vector<int>vis(V, 0);
        vector<int>inRecursion(V, 0);
        bool hasCycle = false;

        for(auto x: edges){
            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
        }

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(adj, vis, inRecursion, ans, i, hasCycle);
            }
        }

        if(hasCycle) return {};

        return ans;
        
    }
};