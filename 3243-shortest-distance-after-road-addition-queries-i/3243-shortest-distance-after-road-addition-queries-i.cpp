class Solution {
public:
    int bfs(int n, unordered_map<int, vector<int>>& adj) {
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int node = q.front();
                q.pop();

                if (node == n - 1)
                    return level;

                for (auto& it : adj[node]) {
                    if (!vis[it]) {
                        q.push(it);
                        vis[it] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i <= n - 2; i++) {
            adj[i].push_back(i + 1);
        }
        vector<int> ans;
        for (auto& it : queries) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            int x = bfs(n, adj);

            ans.push_back(x);
        }
        return ans;
    }
};