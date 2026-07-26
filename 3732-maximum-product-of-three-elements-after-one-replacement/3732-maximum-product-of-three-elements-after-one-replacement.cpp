class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long maxi1 = INT_MIN, maxi2 = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (maxi1 < abs(nums[i])) {
                maxi2 = maxi1;
                maxi1 = abs(nums[i]);
            } else if (maxi2 < abs(nums[i])) {
                maxi2 = abs(nums[i]);
            }
        }
        long long ans = maxi1 * maxi2 * 1LL * 100000;
        return ans;
    }
};