class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN;
        map<int, int, greater<int>> mp;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            mp[nums[i]]++;
        }
        if (k == n)
            return maxi;
        if (k == 1) {
            for (auto& it : mp) {
                if (it.second == 1)
                    return it.first;
            }
            return -1;
        }
        if (mp[nums[0]] == 1 && mp[nums[n - 1]] == 1) {
            return max(nums[0], nums[n - 1]);
        } else if (mp[nums[0]] > 1 && mp[nums[n - 1]] == 1) {
            return nums[n - 1];
        } else if (mp[nums[0]] == 1 && mp[nums[n - 1]] > 1) {
            return nums[0];
        }
        return -1;
    }
};