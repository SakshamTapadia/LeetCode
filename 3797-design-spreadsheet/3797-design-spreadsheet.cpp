class Spreadsheet {
public:
    vector<vector<int>> grid;
    
    pair<int, int> getCellIndices(const string& cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        return {row, col};
    }
    
    int getCellValue(const string& token) {
        if (isdigit(token[0])) {
            return stoi(token);
        }
        auto [row, col] = getCellIndices(token);
        return grid[row][col];
    }

public:
    Spreadsheet(int rows) : grid(rows, vector<int>(26, 0)) {}
    
    void setCell(string cell, int value) {
        auto [row, col] = getCellIndices(cell);
        grid[row][col] = value;
    }
    
    void resetCell(string cell) {
        auto [row, col] = getCellIndices(cell);
        grid[row][col] = 0;
    }
    
    int getValue(string formula) {
        formula = formula.substr(1);
        stringstream ss(formula);
        string token;
        int sum = 0;
        while (getline(ss, token, '+')) {
            sum += getCellValue(token);
        }
        return sum;
    }
};