class Solution {
public:
    void dfs(int k, unordered_map<int, vector<int>>& adj, vector<bool>& vis) {
        vis[k] = true;
        for (auto& it : adj[k]) {
            if (!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> adj;
        vector<bool> vis(n, false);
        for (auto& it : invocations) {
            adj[it[0]].push_back(it[1]);
        }
        dfs(k, adj, vis);
        vector<int> ans;
        for (auto& it : invocations) {
            if (!vis[it[0]] && vis[it[1]]) {
                for (int i = 0; i < n; i++) {
                    ans.push_back(i);
                }
                return ans;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }
        return ans;
    }
};