class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int srcCol = 0;
        int srcRow = 0;

        int distRow = rows - 1;
        int distCol = cols - 1;

        if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1) {
            return -1;
        }

        if (rows == 1 && cols == 1 && grid[0][0] == 0) {
            return 1;
        }

        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, pair<int, int>>> q;

        dist[0][0] = 0;
        q.push({0, {0, 0}});

        int rowArr[] = {-1, 0, 1, 0, -1, 1, 1, -1};
        int colArr[] = {0, 1, 0, -1, 1, 1, -1, -1};

        while (!q.empty()) {
            int r = q.front().second.first;
            int c = q.front().second.second;
            int d = q.front().first;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int tempr = r + rowArr[i];
                int tempc = c + colArr[i];

                if (tempr >= 0 && tempc >= 0 && tempr < rows && tempc < cols &&
                    grid[tempr][tempc] == 0 && d + 1 < dist[tempr][tempc]) {

                    if (tempr == distRow && tempc == distCol) {
                        return d + 2;
                    }
                    dist[tempr][tempc] = d + 1;
                    q.push({d + 1, {tempr, tempc}});
                }
            }
        }

        return -1;
    }
};