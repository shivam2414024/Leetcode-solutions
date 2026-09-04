class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            int mini = INT_MAX;
            for (int j = i; j < n; j++) {
                mini = min(mini, nums[j]);
            }
            if ((maxi - mini) <= k) {
                ans = min(ans, i);
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};