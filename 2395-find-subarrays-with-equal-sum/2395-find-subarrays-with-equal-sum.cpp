class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 1; i < n; i++) {
            int sum = nums[i] + nums[i - 1];
            mp[sum]++;
        }
        for (auto& it : mp) {
            if (it.second >= 2)
                return true;
        }
        return false;
    }
};