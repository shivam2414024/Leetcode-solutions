class Solution {
public:
    int height(unordered_map<int, vector<int>>& adj) {
        queue<int> q;
        q.push(0);
        int ht = 0;
        while (!q.empty()) {
            int sz = q.size();
            ht++;
            for (int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();
                for (auto& it : adj[node]) {
                    q.push(it);
                }
            }
        }
        return ht;
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            int u = parent[i];
            int v = i;
            adj[u].push_back(v);
        }
        int h = height(adj);
        queue<int> q;
        q.push(0);
        int d = 1;
        long long ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();
                ans += ((long long)nums[node] * (h - d + 1));
                for (auto& it : adj[node]) {
                    q.push(it);
                }
            }
            d++;
        }
        return ans;
    }
};