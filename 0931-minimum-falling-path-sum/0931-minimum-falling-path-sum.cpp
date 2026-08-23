class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minSum = INT_MAX;
        for (int i = 0; i < n; i++) {
            vector<vector<int>> dp(n, vector<int>(n));

            for (int j = 0; j < n; j++)
                dp[n - 1][j] = matrix[n - 1][j];

            for (int i = n - 2; i >= 0; i--) {
                for (int j = 0; j < n; j++) {
                    int down = matrix[i][j] + dp[i + 1][j];
                    int leftDiag = INT_MAX;
                    if (j - 1 >= 0)
                        leftDiag = matrix[i][j] + dp[i + 1][j - 1];
                    int rightDiag = INT_MAX;
                    if (j + 1 < n)
                        rightDiag = matrix[i][j] + dp[i + 1][j + 1];
                    dp[i][j] = min({down, leftDiag, rightDiag});
                }
            }
            minSum = min(minSum, dp[0][i]);
        }
        return minSum;
    }
};