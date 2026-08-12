class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 0;
        unordered_map<int, int> mp;
        int l = 0, r = 0, culprit = 0;
        while (r < n && l <= r) {
            mp[nums[r]]++;
            if (mp[nums[r]] == k + 1) {
                culprit++;
            }
            if (culprit > 0) {
                mp[nums[l]]--;
                if (mp[nums[l]] == k) {
                    culprit--;
                }
                l++;
            }
            if (culprit == 0) {
                len = max(len, r - l + 1);
            }
            r++;
        }
        return len;
    }
};