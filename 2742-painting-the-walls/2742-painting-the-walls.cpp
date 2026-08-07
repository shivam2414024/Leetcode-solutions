class Solution {
public:
    int solve(int n, vector<int>& cost, vector<int>& time, int i, int remain,
              vector<vector<int>>& dp) {
        if (remain <= 0)
            return 0;
        if (i >= n)
            return INT_MAX;
        if (dp[i][remain] != -1)
            return dp[i][remain];
        int paid_painter = INT_MAX;
        int next = solve(n, cost, time, i + 1, remain - 1 - time[i], dp);
        if (next != INT_MAX)
            paid_painter = cost[i] + next;
        int free_painter = solve(n, cost, time, i + 1, remain, dp);
        return dp[i][remain] = min(paid_painter, free_painter);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(n, cost, time, 0, n, dp);
    }
};