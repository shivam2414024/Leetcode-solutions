class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long GCD = __gcd(nums[i], nums[j]);
                long long val = (nums[i] * 1LL * nums[j]) / (GCD * GCD);
                maxi = max(maxi, val);
            }
        }
        return maxi;
    }
};