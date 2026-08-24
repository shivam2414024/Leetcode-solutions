class Solution {
public:
    int MOD = 2 * 1e9;
    int solve(int m, int n, int i, int j, vector<vector<int>>& obstacleGrid,
              vector<vector<int>>& dp) {
        if (obstacleGrid[i][j] == 1)
            return 0;
        if (i == m - 1 && j == n - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];

        int down = 0;
        if (i + 1 < m)
            down = solve(m, n, i + 1, j, obstacleGrid, dp);
        int right = 0;
        if (j + 1 < n)
            right = solve(m, n, i, j + 1, obstacleGrid, dp);

        return dp[i][j] = (down + right) % MOD;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m, n, 0, 0, obstacleGrid, dp);
    }
};