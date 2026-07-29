class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {entrance[0], entrance[1]}});
        dis[entrance[0]][entrance[1]] = 0;
        vector<int> dr = {-1, 0, +1, 0};
        vector<int> dc = {0, +1, 0, -1};
        while (!q.empty()) {
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    maze[nrow][ncol] == '.' && dist + 1 < dis[nrow][ncol]) {
                    dis[nrow][ncol] = dist + 1;
                    if (nrow == 0 || nrow == n - 1 || ncol == 0 || ncol == m - 1)
                        return dist + 1;
                    q.push({dist + 1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};