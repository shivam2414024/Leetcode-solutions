class Solution {
public:
    // 0 --> D , 1 --> U , 2 --> R , 3 --> L
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        vector<vector<vector<vector<int>>>> dp(
            m, vector<vector<vector<int>>>(
                   n, vector<vector<int>>(k + 1, vector<int>(4, INT_MAX))));
        dp[0][0][0][0] = grid[0][0];

        if (m > 1)
            dp[1][0][0][0] = grid[0][0] + grid[1][0];
        if (n > 1)
            dp[0][1][0][2] = grid[0][0] + grid[0][1];

        priority_queue<tuple<int, int, int, int, int>> pq;

        if (m > 1)
            pq.push({-dp[1][0][0][0], 1, 0, 0, 0});
        if (n > 1)
            pq.push({-dp[0][1][0][2], 0, 1, 0, 2});

        while (!pq.empty()) {
            auto [cost, i, j, t, dir] = pq.top();
            pq.pop();

            for (int l = 0; l < 4; l++) {
                int i_ = i + dr[l];
                int j_ = j + dc[l];
                int t_ = (dir != l) + t;

                if (t_ > k)
                    continue;

                if (i_ >= 0 && j_ >= 0 && i_ < m && j_ < n) {
                    if (dp[i_][j_][t_][l] > (-cost + grid[i_][j_])) {
                        dp[i_][j_][t_][l] = -cost + grid[i_][j_];
                        pq.push({-dp[i_][j_][t_][l], i_, j_, t_, l});
                    }
                }
            }
        }

        int ans = INT_MAX;

        for (int i = 0; i < k + 1; i++) {
            for (int j = 0; j < 4; j++) {
                ans = min(ans, dp[m - 1][n - 1][i][j]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};