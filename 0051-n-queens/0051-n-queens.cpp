class Solution {
public:
    // TC: O(N!)  SC: O(N)
    void solve(int n, vector<string>& board, int row, unordered_set<int>& cols,
               unordered_set<int>& diag, unordered_set<int>& antiDiag,
               vector<vector<string>>& ans) {
        if (row >= n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            int diagConst = row - col;
            int antiDiagConst = row + col;

            if (cols.find(col) != cols.end() ||
                diag.find(diagConst) != diag.end() ||
                antiDiag.find(antiDiagConst) != antiDiag.end()) {
                continue;
            }

            cols.insert(col);
            diag.insert(diagConst);
            antiDiag.insert(antiDiagConst);

            board[row][col] = 'Q';

            solve(n, board, row + 1, cols, diag, antiDiag, ans);

            cols.erase(col);
            diag.erase(diagConst);
            antiDiag.erase(antiDiagConst);

            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        unordered_set<int> cols, diag, antiDiag;
        vector<vector<string>> ans;
        solve(n, board, 0, cols, diag, antiDiag, ans);
        return ans;
    }
};