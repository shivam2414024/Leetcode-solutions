class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        int n = colors.size();
        vector<int> inDegree(n);
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        queue<int> q;
        vector<vector<int>> t(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                t[i][colors[i] - 'a'] = 1;
            }
        }
        int ans = 0;
        int countNodes = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            countNodes++;
            ans = max(ans, t[u][colors[u] - 'a']);
            for (auto& v : adj[u]) {
                for (int i = 0; i < 26; i++) {
                    t[v][i] = max(t[v][i], t[u][i] + (colors[v] - 'a' == i));
                }
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        if (countNodes < n)
            return -1;
        return ans;
    }
};