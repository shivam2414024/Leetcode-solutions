class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 0;
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        while (r < n && l <= r) {
            mp[nums[r]]++;
            while (mp[nums[r]] > k) {
                mp[nums[l]]--;
                l++;
            }
            len = max(len, r - l + 1);
            r++;
        }
        return len;
    }
};