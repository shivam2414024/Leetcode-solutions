class Solution {
public:
    int solve(int m, int n, int i, int j, vector<vector<int>>& dungeon,
              vector<vector<int>>& dp) {
        if (i >= m || j >= n)
            return 1e9;

        if (i == m - 1 && j == n - 1) {
            if (dungeon[i][j] > 0)
                return 1;
            return abs(dungeon[i][j]) + 1;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solve(m, n, i, j + 1, dungeon, dp);
        int down = solve(m, n, i + 1, j, dungeon, dp);

        int result = min(right, down) - dungeon[i][j];

        return dp[i][j] = (result > 0) ? result : 1;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m, n, 0, 0, dungeon, dp);
    }
};