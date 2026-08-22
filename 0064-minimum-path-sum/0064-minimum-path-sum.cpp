class Solution {
public:
    // int solve(int m, int n, int i, int j, vector<vector<int>>& grid,
    //           vector<vector<int>>& dp) {
    //     if (i >= m || i < 0 || j >= n || j < 0) {
    //         return 1e9;
    //     }

    //     if (i == m - 1 && j == n - 1) {
    //         return grid[i][j];
    //     }

    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     int right = grid[i][j] + solve(m, n, i, j + 1, grid, dp);
    //     int down = grid[i][j] + solve(m, n, i + 1, j, grid, dp);

    //     return dp[i][j] = min(right, down);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int right = grid[i][j] + dp[i][j - 1];
                int down = grid[i][j] + dp[i - 1][j];
                dp[i][j] = min(right, down);
            }
        }

        return dp[m - 1][n - 1];
    }
};