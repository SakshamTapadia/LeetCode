class Solution {
    void check(vector<vector<int>>& visited, int n, int m, int i, int j)
    {
        for(int k=j+1;k<m;k++)
        {
            if(visited[i][k] == 1 || visited[i][k] == 2) break;
            visited[i][k] = 3;
        }
        for(int k=j-1;k>=0;k--)
        {
            if(visited[i][k] == 1 || visited[i][k] == 2) break;
            visited[i][k] = 3;
        }
        for(int k=i+1;k<n;k++)
        {
            if(visited[k][j] == 1 || visited[k][j] == 2) break;
            visited[k][j] = 3;
        }
        for(int k=i-1;k>=0;k--)
        {
            if(visited[k][j] == 1 || visited[k][j] == 2) break;
            visited[k][j] = 3;
        }
    }
public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(auto& vec : walls)
        {
            int x = vec[0];
            int y = vec[1];
            visited[x][y] = 1;
        }
        for(auto& vec : guards)
        {
            int x = vec[0];
            int y = vec[1];
            visited[x][y] = 2;
        }
        for(auto& vec : guards)
        {
            int x = vec[0];
            int y = vec[1];
            check(visited, n, m, x, y);
        }

        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j] == 0) count++;
            }
        }
        return count;
    }
};