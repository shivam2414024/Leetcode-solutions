class Solution {
public:
    void dfs(vector<vector<int>>& heights, int i, int j,
             int prev, vector<vector<bool>>& vis, vector<int>& dr,
             vector<int>& dc) {
        if (i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size())
            return;
        if (heights[i][j] < prev || vis[i][j])
            return;
        vis[i][j] = true;

        for (int k = 0; k < 4; k++) {
            int _i = i + dr[k];
            int _j = j + dc[k];

            dfs(heights, _i, _j, heights[i][j], vis, dr, dc);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacificVis(m, vector<bool>(n, false));
        vector<vector<bool>> atlanticVis(m, vector<bool>(n, false));

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        for (int j = 0; j < n; j++) {
            dfs(heights, 0, j, INT_MIN, pacificVis, dr, dc);
            dfs(heights, m - 1, j, INT_MIN, atlanticVis, dr, dc);
        }

        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, INT_MIN, pacificVis, dr, dc);
            dfs(heights, i, n - 1, INT_MIN, atlanticVis, dr, dc);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacificVis[i][j] && atlanticVis[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};