class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }
        if (q.size() == (n * n))
            return -1;
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        int dist = 0;
        while (!q.empty()) {
            int sz = q.size();
            dist++;
            while (sz--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int i_ = i + dr[k];
                    int j_ = j + dc[k];
                    if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < n &&
                        grid[i_][j_] == 0 && !vis[i_][j_]) {
                        q.push({i_, j_});
                        vis[i_][j_] = true;
                    }
                }
            }
        }
        return dist - 1;
    }
};