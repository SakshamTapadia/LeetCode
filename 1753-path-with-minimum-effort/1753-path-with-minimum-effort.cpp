class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int rowArr[4] = {-1, 0, 1, 0};
        int colArr[4] = {0, 1, 0, -1};

        while (!pq.empty()) {
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            int d = pq.top().first;
            pq.pop();
            if (r == rows - 1 && c == cols - 1) {
                return d;
            }

            for (int i = 0; i < 4; i++) {
                int adjRow = r + rowArr[i];
                int adjCol = c + colArr[i];
                if (adjRow >= 0 && adjRow < rows && adjCol >= 0 &&
                    adjCol < cols) {
                    int effort = abs(heights[adjRow][adjCol] - heights[r][c]);
                    int maxEffort = max(effort, dist[r][c]);

                    if (maxEffort < dist[adjRow][adjCol]) {
                        dist[adjRow][adjCol] = maxEffort;
                        pq.push({maxEffort, {adjRow, adjCol}});
                    }
                }
            }
        }

        return 0;
    }
};