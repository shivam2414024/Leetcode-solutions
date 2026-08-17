class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> num;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    num.push_back({i, j});
                }
            }
        }
        if (num.empty())
            return -1;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int mini = INT_MAX;
                if (grid[i][j] == 0) {
                    for (int k = 0; k < num.size(); k++) {
                        int x = num[k].first;
                        int y = num[k].second;
                        mini = min(mini, abs(i - x) + abs(j - y));
                    }
                }
                if (mini != INT_MAX)
                    maxi = max(maxi, mini);
            }
        }
        return maxi == INT_MIN ? -1 : maxi;
    }
};