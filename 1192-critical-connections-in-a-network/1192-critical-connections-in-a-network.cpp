class Solution {
public:
    void dfs(int node, int parent, unordered_map<int, vector<int>>& adj,
             vector<bool>& vis, vector<int>& tin, vector<int>& low, int& timer,
             vector<vector<int>>& bridges) {
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        for (auto& it : adj[node]) {
            if (it == parent)
                continue;
            if (!vis[it]) {
                dfs(it, node, adj, vis, tin, low, timer, bridges);
                low[node] = min(low[node], low[it]);
                if (low[it] > tin[node])
                    bridges.push_back({it, node});
            } else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> adj;
        for (auto& it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n, false);
        int timer = 1;
        vector<int> tin(n, 0);
        vector<int> low(n, 0);
        vector<vector<int>> bridges;
        dfs(0, -1, adj, vis, tin, low, timer, bridges);
        return bridges;
    }
};