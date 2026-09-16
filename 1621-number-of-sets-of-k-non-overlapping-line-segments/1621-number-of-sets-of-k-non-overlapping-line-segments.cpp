class Solution {
public:
    int M = 1e9 + 7;
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1));

        for (int i = 0; i <= n; i++) {
            dp[0][i] = (i < n) ? 1 : 0;
        }

        for (int K = 1; K <= k; K++) {
            vector<int> prevRowSum(n + 1);
            for (int x = n - 1; x >= 0; x--) {
                prevRowSum[x] = (prevRowSum[x + 1] + dp[K - 1][x]) % M;
            }
            for (int i = n - 1; i >= 0; i--) {
                long long skip = dp[K][i + 1];
                long long take = prevRowSum[i + 1];
                dp[K][i] = (take + skip) % M;
            }
        }
        return dp[k][0];
    }
};