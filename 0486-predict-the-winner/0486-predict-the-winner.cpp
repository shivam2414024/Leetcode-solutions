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
        int take_i = nums[i] + min(solve(i + 2, j, nums, dp),
                                   solve(i + 1, j - 1, nums, dp));
        int take_j = nums[j] + min(solve(i, j - 2, nums, dp),
                                   solve(i + 1, j - 1, nums, dp));
        return dp[i][j] = max(take_i, take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int total_score = accumulate(nums.begin(), nums.end(), 0);
        int player1_score = solve(0, n - 1, nums, dp);
        int player2_score = total_score - player1_score;
        return player1_score >= player2_score;
    }
};