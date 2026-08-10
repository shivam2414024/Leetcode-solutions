class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> adj;
        for (auto& it : connections) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        set<pair<int, int>> st;
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(0);
        vis[0] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = true;
                    auto pair = make_pair(node, it);
                    st.insert(pair);
                    q.push(it);
                }
            }
        }
        int count = 0;
        for (auto& it : connections) {
            auto P = make_pair(it[0], it[1]);
            if (st.find(P) != st.end())
                count++;
        }
        return count;
    }
};