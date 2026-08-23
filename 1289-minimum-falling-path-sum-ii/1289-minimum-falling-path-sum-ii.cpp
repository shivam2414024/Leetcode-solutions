class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int minSum = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int l = 0; l < n; l++) {
            dp[n - 1][l] = grid[n - 1][l];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int t = 0; t < n; t++) {
                int mini = 1e9;
                for (int k = 0; k < n; k++) {
                    if (t != k)
                        mini = min(mini, dp[i + 1][k]);
                }
                dp[i][t] = mini + grid[i][t];
            }
        }
        for (int j = 0; j < n; j++) {
            minSum = min(minSum, dp[0][j]);
        }

        return minSum;
    }
};