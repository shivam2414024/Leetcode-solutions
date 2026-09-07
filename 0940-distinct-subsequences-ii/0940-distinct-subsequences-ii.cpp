class Solution {
public:
    int M = 1e9 + 7;
    int solve(int n, string& s, vector<int>& prev, vector<int>& dp) {
        if (n == 0)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        long long total = (solve(n - 1, s, prev, dp) * 2LL) % M;

        if (prev[n] != 0) {
            long long duplicates = solve(prev[n] - 1, s, prev, dp);
            total = (total - duplicates + M) % M;
        }

        return dp[n] = total;
    }
    int distinctSubseqII(string s) {
        int n = s.size();

        vector<int> dp(n+1, -1);

        vector<int> lastSeen(26, 0);
        vector<int> prev(n + 1);

        for (int i = 1; i <= n; i++) {
            int idx = s[i - 1] - 'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }

        return (solve(n, s, prev, dp) - 1 + M) % M;
    }
};