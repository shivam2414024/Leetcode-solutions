class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        vector<int> diff(maxi + 2, 0);
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            int l = max(nums[i] - k, 0);
            int r = min(nums[i] + k, maxi);

            diff[l] += 1;
            if (r + 1 < maxi)
                diff[r + 1] -= 1;
        }
        int ans = INT_MIN;
        for (int i = 0; i <= maxi; i++) {
            if (i > 0)
                diff[i] = diff[i] + diff[i - 1];
            int curr_freq = freq[i];
            int needConversion = diff[i] - curr_freq;
            int maxPossible = min(needConversion, numOperations);
            ans = max(ans, curr_freq + maxPossible);
        }
        return ans;
    }
};