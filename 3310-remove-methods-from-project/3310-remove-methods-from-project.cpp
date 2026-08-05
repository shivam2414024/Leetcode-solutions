class Solution {
public:
    void dfs(int k, unordered_map<int, vector<int>>& adj, vector<bool>& vis,
             set<int>& st) {
        st.insert(k);
        vis[k] = true;
        for (auto& it : adj[k]) {
            if (!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }
    }
    void check(int node, unordered_map<int, vector<int>>& adj,
               vector<bool>& vis, vector<int>& ans, set<int>& st) {
        vis[node] = true;
        for (auto& it : adj[node]) {
            if (!vis[it]) {
                check(it, adj, vis, ans, st);
                ans.push_back(it);
            }
            if (st.find(it) != st.end())
                ans.push_back(it);
        }
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> adj;
        for (auto& it : invocations) {
            adj[it[0]].push_back(it[1]);
        }
        vector<bool> vis(n, false);
        set<int> st;
        vector<int> ans;
        dfs(k, adj, vis, st);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans.push_back(i);
                check(i, adj, vis, ans, st);
            }
        }
        bool flag = false;
        for (int i = 0; i < ans.size(); i++) {
            if (st.find(ans[i]) != st.end()) {
                flag = true;
                break;
            }
        }
        if (flag) {
            ans.clear();
            for (int i = 0; i < n; i++)
                ans.push_back(i);
        }
        return ans;
    }
};