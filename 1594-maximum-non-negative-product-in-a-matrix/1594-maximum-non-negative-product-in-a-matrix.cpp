class Solution {
public:
    typedef long long ll;
    int MOD = 1e9 + 7;
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<ll, ll>>> dp(m, vector<pair<ll, ll>>(n));

        dp[0][0] = make_pair(grid[0][0], grid[0][0]);

        for (int i = 1; i < m; i++) {
            dp[i][0] = make_pair(grid[i][0] * dp[i - 1][0].first,
                                 grid[i][0] * dp[i - 1][0].second);
        }

        for (int j = 1; j < n; j++) {
            dp[0][j] = make_pair(grid[0][j] * dp[0][j - 1].first,
                                 grid[0][j] * dp[0][j - 1].second);
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long upMax = dp[i - 1][j].first;
                long long upMin = dp[i - 1][j].second;
                long long leftMax = dp[i][j - 1].first;
                long long leftMin = dp[i][j - 1].second;

                dp[i][j].first =
                    max({grid[i][j] * upMax, grid[i][j] * upMin,
                         grid[i][j] * leftMax, grid[i][j] * leftMin});
                dp[i][j].second =
                    min({grid[i][j] * upMax, grid[i][j] * upMin,
                         grid[i][j] * leftMax, grid[i][j] * leftMin});
            }
        }

        ll maxProd = dp[m - 1][n - 1].first;

        return maxProd < 0 ? -1 : maxProd % MOD;
    }
};