class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n));
        int nextMinCol1 = -1;
        int nextMinCol2 = -1;
        for (int l = 0; l < n; l++) {
            dp[n - 1][l] = grid[n - 1][l];

            if (nextMinCol1 == -1 || dp[n - 1][l] <= dp[n - 1][nextMinCol1]) {
                nextMinCol2 = nextMinCol1;
                nextMinCol1 = l;
            } else if (nextMinCol2 == -1 ||
                       dp[n - 1][l] <= dp[n - 1][nextMinCol2]) {
                nextMinCol2 = l;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            int minCol1 = -1;
            int minCol2 = -1;
            for (int t = 0; t < n; t++) {
                if (t != nextMinCol1) {
                    dp[i][t] = grid[i][t] + dp[i + 1][nextMinCol1];
                } else {
                    dp[i][t] = grid[i][t] + dp[i + 1][nextMinCol2];
                }

                if (minCol1 == -1 || dp[i][t] <= dp[i][minCol1]) {
                    minCol2 = minCol1;
                    minCol1 = t;
                } else if (minCol2 == -1 || dp[i][t] <= dp[i][minCol2]) {
                    minCol2 = t;
                }
            }
            nextMinCol1 = minCol1;
            nextMinCol2 = minCol2;
        }

        return dp[0][nextMinCol1];
    }
};