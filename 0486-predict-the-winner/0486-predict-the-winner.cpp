class Solution {
public:
    // Optimal Game Strategy problem
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        if (i == j)
            return nums[i];
        if (dp[i][j] != -1)
            return dp[i][j];
        int take_i = nums[i] - solve(i + 1, j, nums, dp);
        int take_j = nums[j] - solve(i, j - 1, nums, dp);
        return dp[i][j] = max(take_i, take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, n - 1, nums, dp) >= 0;
    }
};