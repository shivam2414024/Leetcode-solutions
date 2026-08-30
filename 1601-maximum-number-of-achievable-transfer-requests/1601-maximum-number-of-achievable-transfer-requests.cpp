class Solution {
public:
    void solve(int m, int n, vector<vector<int>>& requests, vector<int>& build,
               int count, int idx, int& ans) {
        if (idx == m) {
            bool flag = true;
            for (int i = 0; i < n; i++) {
                if (build[i] != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans = max(ans, count);
            return;
        }
        int from = requests[idx][0];
        int to = requests[idx][1];

        build[from] -= 1;
        build[to] += 1;

        solve(m, n, requests, build, count + 1, idx + 1, ans);

        build[from] += 1;
        build[to] -= 1;

        solve(m, n, requests, build, count, idx + 1, ans);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        vector<int> build(n);
        int ans = 0;
        solve(m, n, requests, build, 0, 0, ans);
        return ans;
    }
};