class Solution {
public: 
    #define P pair<int, pair<int,int>>
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        while (!pq.empty()) {
            int d = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if (nrow < 0 || nrow >= m || ncol < 0 || ncol >= n)
                    continue;
                int wt = (grid[nrow][ncol] == 1) ? 1 : 0;

                if (wt + d < dist[nrow][ncol]) {
                    pq.push({wt + d, {nrow, ncol}});
                    dist[nrow][ncol] = wt + d;
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};