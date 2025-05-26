class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int numVertices = colors.size();
        vector<vector<int>> graph(numVertices);
        vector<int> inDegree(numVertices); 
        for (auto& edge : edges) {
            int from = edge[0], to = edge[1];
            graph[from].push_back(to);
            ++inDegree[to];
        }

        queue<int> processingQueue; 
        vector<vector<int>> dp(numVertices, vector<int>(26));
        for (int i = 0; i < numVertices; ++i) {
            if (inDegree[i] == 0) {
                processingQueue.push(i);
                int colorIndex = colors[i] - 'a'; 
                dp[i][colorIndex]++;
            }
        }

        int processedCount = 0; 
        int maxPathValue = 1;
        while (!processingQueue.empty()) {
            int currentVertex = processingQueue.front();
            processingQueue.pop();
            ++processedCount;

            for (int neighbor : graph[currentVertex]) {
                --inDegree[neighbor];
                if (inDegree[neighbor] == 0) {
                    processingQueue.push(neighbor);
                }
                int neighborColorIndex = colors[neighbor] - 'a';
                for (int color = 0; color < 26; ++color) {
                    
                    dp[neighbor][color] = max(dp[neighbor][color], dp[currentVertex][color] + (neighborColorIndex == color));
                    maxPathValue = max(maxPathValue, dp[neighbor][color]);
                }
            }
        }
        return processedCount == numVertices ? maxPathValue : -1;
    }
};