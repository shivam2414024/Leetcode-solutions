class Solution {
public:
    int MOD = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> countBits(32, 0);
        for (int i = 0; i < n; i++) {
            for (int b = 0; b < 32; b++) {
                if (nums[i] & (1 << b))
                    countBits[b]++;
            }
        }
        int ans = 0;
        while (k--) {
            int num = 0;
            for (int b = 0; b < 32; b++) {
                if (countBits[b] > 0) {
                    num = num | (1 << b);
                    countBits[b]--;
                }
            }
            ans = (ans + 1LL * num * num) % MOD;
        }
        return ans;
    }
};