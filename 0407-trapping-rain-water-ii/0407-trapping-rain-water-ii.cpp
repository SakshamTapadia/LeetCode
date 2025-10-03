class Solution {
public:
    vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    
    bool check(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    int trapRainWater(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int col = 0; col < m; col++) {
            pq.push({mat[0][col], {0, col}});
            pq.push({mat[n-1][col], {n-1, col}});
            vis[0][col] = 1;
            vis[n-1][col] = 1;
        }
        for (int row = 1; row < n-1; row++) {
            pq.push({mat[row][0], {row, 0}});
            pq.push({mat[row][m-1], {row, m-1}});
            vis[row][0] = 1;
            vis[row][m-1] = 1;
        }
        
        int total = 0;
        
        while (!pq.empty()) {
            auto [height, cell] = pq.top();
            pq.pop();
            
            int i = cell.first;
            int j = cell.second;
            
            for (auto dir : dirs) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];
                
                if (check(i_, j_, n, m) && !vis[i_][j_]) {
                    vis[i_][j_] = 1;
                    if (mat[i_][j_] < height) {
                        total += (height - mat[i_][j_]);
                    }
                    pq.push({max(height, mat[i_][j_]), {i_, j_}});
                }
            }
        }
        
        return total;
    }
};