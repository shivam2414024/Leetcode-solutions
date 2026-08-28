class Solution {
public:
    int solve(int n, int m, string& s, string& t, int i, int j,
              vector<vector<int>>& dp) {
        if (i == n && j != m)
            return 0;

        if (j == m)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j]) {
            int take = solve(n, m, s, t, i + 1, j + 1, dp);
            int notTake = solve(n, m, s, t, i + 1, j, dp);

            return dp[i][j] = take + notTake;
        }

        return dp[i][j] = solve(n, m, s, t, i + 1, j, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n, m, s, t, 0, 0, dp);
    }
};