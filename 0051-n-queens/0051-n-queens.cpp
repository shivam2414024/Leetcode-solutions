class Solution {
public:
    // TC: O(N!)  SC: O(N)
    bool isValid(int n, vector<string>& board, int row, int col){
        // upward check
        for(int i=row-1; i>=0; i--){
            if(board[i][col] == 'Q') return false;
        }

        // left diagonal check
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }

        // right diagonal check
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }
    void solve(int n, vector<string>& board, int row, vector<vector<string>>& ans){
        if(row >= n){
            ans.push_back(board);
            return;
        }
        for(int col=0; col < n; col++){
            if(isValid(n, board, row, col)){
                board[row][col] = 'Q';
                solve(n, board, row+1, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(n, board, 0, ans);
        return ans;
    }
};