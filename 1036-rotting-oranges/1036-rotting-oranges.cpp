class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j] == 1) fresh++;
            }
        }

        if (fresh == 0) return 0;
        if (q.empty()) return -1;

        int minutes = -1;
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,-1}, {0,1}};

        while (!q.empty()) {
            int size = q.size();
            while (size > 0) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : dirs) {
                    int i = x + dx;
                    int j = y + dy;
                    if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1) {
                        grid[i][j] = 2;
                        fresh--;
                        q.push({i, j});
                    }
                }

                size--;
            }
            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
