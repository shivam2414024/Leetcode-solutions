class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                int down = 0;
                if (i >= 1)
                    down = dp[i - 1][j];
                int right = 0;
                if (j >= 1)
                    right = dp[i][j - 1];
                dp[i][j] = right + down;
            }
        }
        return dp[m - 1][n - 1];
    }
};