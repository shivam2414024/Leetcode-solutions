class Solution {
public:
    int solve(int n, int i, vector<int>& pref, vector<int>& dp) {
        if (i == n - 1)
            return pref[n - 1];

        if (dp[i] != -1)
            return dp[i];

        int take = pref[i] - solve(n, i + 1, pref, dp);
        int notTake = solve(n, i + 1, pref, dp);

        return dp[i] = max(take, notTake);
    }
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> pref(n);
        pref[0] = stones[0];
        for (int i = 1; i < n; i++)
            pref[i] = stones[i] + pref[i - 1];
        vector<int> dp(n, -1);
        return solve(n, 1, pref, dp);
    }
};