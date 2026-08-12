class Solution {
public:
    char dfs(unordered_map<char, vector<char>>& adj, char curr_ch,
             vector<int>& vis) {
        vis[curr_ch - 'a'] = 1;
        char minChar = curr_ch;
        for (auto& ch : adj[curr_ch]) {
            if (!vis[ch - 'a']) {
                minChar = min(minChar, dfs(adj, ch, vis));
            }
        }
        return minChar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        int m = baseStr.size();
        unordered_map<char, vector<char>> adj;
        for (int i = 0; i < n; i++) {
            char u = s1[i];
            char v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string ans = "";
        for (int i = 0; i < m; i++) {
            char ch = baseStr[i];
            vector<int> vis(26, 0);
            char minChar = dfs(adj, ch, vis);
            ans.push_back(minChar);
        }
        return ans;
    }
};