class Solution {
public:
    int solve(int n, vector<int>& nums, int sum, int& target, vector<int>& dp) {
        if (sum == target) {
            return 1;
        }

        if (dp[sum] != -1)
            return dp[sum];

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (sum + nums[i] <= target) {
                ans += solve(n, nums, sum + nums[i], target, dp);
            }
        }

        return dp[sum] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target + 1, -1);
        int sum = 0;
        return solve(n, nums, sum, target, dp);
    }
};