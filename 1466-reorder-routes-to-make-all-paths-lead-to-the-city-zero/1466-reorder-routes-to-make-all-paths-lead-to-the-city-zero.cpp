class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& it : connections) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(0);
        vis[0] = true;
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& it : adj[node]) {
                int adjNode = it.first;
                int real = it.second;
                if (!vis[adjNode]) {
                    q.push(adjNode);
                    count += real;
                    vis[adjNode] = true;
                }
            }
        }
        return count;
    }
};