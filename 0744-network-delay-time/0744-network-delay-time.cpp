class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n+1);

        for (auto time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[0] = 0;
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0 , k});

        while(!pq.empty()){
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto n : adj[node]){
                int adjNode = n.first;
                int adjTime = n.second;

                if(time + adjTime < dist[adjNode]){
                    dist[adjNode] = time + adjTime;
                    pq.push({dist[adjNode] , adjNode});
                }
            }
        }

        int temp = *max_element(dist.begin() , dist.end());
        if(temp == INT_MAX){
            return -1;
        }else{
            return temp;
        }
    }
};