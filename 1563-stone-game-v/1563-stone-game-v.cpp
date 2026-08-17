class Solution {
public:
    // TC: O(n^3) SC: O(n^2) 
    int solve(int l, int r, vector<int>& cumSum, vector<vector<int>>& dp) {
        if (l >= r)
            return 0;
        if (dp[l][r] != -1)
            return dp[l][r];
        int score = 0;
        for (int mid = l; mid <= r - 1; mid++) {
            int leftSum = cumSum[mid] - (l > 0 ? cumSum[l - 1] : 0);
            int rightSum = cumSum[r] - cumSum[mid];
            if (leftSum < rightSum) {
                score = max(score, leftSum + solve(l, mid, cumSum, dp));
            } else if (leftSum > rightSum) {
                score = max(score, rightSum + solve(mid + 1, r, cumSum, dp));
            } else {
                score = max({score, leftSum + solve(l, mid, cumSum, dp),
                             rightSum + solve(mid + 1, r, cumSum, dp)});
            }
        }
        return dp[l][r] = score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        vector<int> cumSum(n);
        cumSum[0] = stoneValue[0];
        for (int i = 1; i < n; i++) {
            cumSum[i] = cumSum[i - 1] + stoneValue[i];
        }
        return solve(0, n - 1, cumSum, dp);
    }
};