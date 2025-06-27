class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj, vector<int>&vis, int u){

        vis[u] = true;

        for(auto padosi: adj[u]){

            if(!vis[padosi]){
                dfs(adj, vis,  padosi);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& edges) {

        unordered_map<int,vector<int>>adj;
        int n = edges.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                if(edges[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }

            }
        }

        vector<int>vis(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(adj, vis, i);
                ans++;
            }
        }

        return ans;        
    }
};