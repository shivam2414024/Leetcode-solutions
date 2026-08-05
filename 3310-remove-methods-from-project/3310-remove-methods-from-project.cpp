class Solution {
public:
    void dfs(int k, unordered_map<int, vector<int>>& adj, vector<bool>& vis,
             vector<int>& inDegree) {
        vis[k] = true;
        for (auto& it : adj[k]) {
            inDegree[it]--;
            if (!vis[it]) {
                dfs(it, adj, vis, inDegree);
            }
        }
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> adj;
        vector<bool> vis(n, false);
        vector<int> inDegree(n, 0);
        for (auto& it : invocations) {
            adj[it[0]].push_back(it[1]);
            inDegree[it[1]]++;
        }
        dfs(k, adj, vis, inDegree);
        vector<int> ans;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (vis[i] && inDegree[i] != 0) {
                flag = true;
            }
            if (!vis[i]) {
                ans.push_back(i);
            }
        }
        if (flag) {
            vector<int> nums(n);
            for (int i = 0; i < n; i++) {
                nums[i] = i;
            }
            return nums;
        }
        return ans;
    }
};