class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(int n, int m, int k, int idx, int searchCost, int maxVal,
              vector<vector<vector<int>>>& dp) {
        if (searchCost > k)
            return 0;

        if (idx == n) {
            if (searchCost == k)
                return 1;
            return 0;
        }

        if (dp[idx][searchCost][maxVal] != -1)
            return dp[idx][searchCost][maxVal];

        int result = 0;

        for (int i = 1; i <= m; i++) {
            if (i > maxVal)
                result =
                    (result + solve(n, m, k, idx + 1, searchCost + 1, i, dp)) %
                    MOD;
            else
                result =
                    (result + solve(n, m, k, idx + 1, searchCost, maxVal, dp)) %
                    MOD;
        }

        return dp[idx][searchCost][maxVal] = result % MOD;
    }
    int numOfArrays(int n, int m, int k) {

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(k + 1, vector<int>(m + 1, -1)));

        return solve(n, m, k, 0, 0, 0, dp);
    }
};