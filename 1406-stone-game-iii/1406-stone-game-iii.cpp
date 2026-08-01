class Solution {
public:
    int solve(int i, int n, vector<int>& stoneValue, vector<int>& dp) {
        if (i >= n)
            return 0;
        if(dp[i] != -1) return dp[i];
        int result = INT_MIN;
        result = max(result, stoneValue[i] - solve(i + 1, n, stoneValue, dp));
        if (i + 1 < n)
            result = max(result, stoneValue[i] + stoneValue[i + 1] -
                                     solve(i + 2, n, stoneValue, dp));
        if (i + 2 < n)
            result = max(result, stoneValue[i] + stoneValue[i + 1] +
                                     stoneValue[i + 2] -
                                     solve(i + 3, n, stoneValue, dp));
        return dp[i] = result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+1, -1);
        if (solve(0, n, stoneValue, dp) > 0)
            return "Alice";
        else if (solve(0, n, stoneValue, dp) == 0)
            return "Tie";
        return "Bob";
    }
};