class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool dfs(vector<vector<char>>& board, string& word, int i, int x, int y) {
        if (i == word.size())
            return true;
        if (x < 0 or x >= board.size() or y < 0 or y >= board[x].size())
            return false;
        if (word[i] != board[x][y])
            return false;

        char temp = board[x][y];
        board[x][y] = '-1';
        for (int d = 0; d < 4; d++) {
            if (dfs(board, word, i + 1, x + dx[d], y + dy[d])) {
                return true;
            }
        }
        board[x][y] = temp;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        unordered_map<char, int> boardCount, wordCount;
        for (auto& row : board)
            for (char c : row)
                boardCount[c]++;
        for (char c : word) {
            wordCount[c]++;
            if (wordCount[c] > boardCount[c])
                return false;
        }

        if (boardCount[word[0]] > boardCount[word.back()])
            reverse(word.begin(), word.end());
        
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};