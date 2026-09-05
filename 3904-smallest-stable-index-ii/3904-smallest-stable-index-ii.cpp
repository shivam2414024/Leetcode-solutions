class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mini(n);
        mini[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            mini[i] = min(mini[i + 1], nums[i]);
        }
        int maxi = INT_MIN;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            int minimum = mini[i];
            if ((maxi - minimum) <= k) {
                ans = min(ans, i);
            }
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};