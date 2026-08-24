class Solution {
public:
    // int solve(int m, int i, int j, vector<vector<int>>& triangle,
    //           vector<vector<int>>& dp) {
    //     if (i >= m || j >= triangle[i].size())
    //         return 1e9;

    //     if (i == m - 1 && j < triangle[i].size())
    //         return triangle[i][j];

    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     int down = triangle[i][j] + solve(m, i + 1, j, triangle, dp);
    //     int diagRight = triangle[i][j] + solve(m, i + 1, j + 1, triangle, dp);

    //     return dp[i][j] = min(down, diagRight);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m));

        for (int j = 0; j < triangle[m - 1].size(); j++)
            dp[m - 1][j] = triangle[m - 1][j];

        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {

                int down = triangle[i][j] + dp[i + 1][j];
                int diagRight = triangle[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min(down, diagRight);
            }
        }
        return dp[0][0];
    }
};