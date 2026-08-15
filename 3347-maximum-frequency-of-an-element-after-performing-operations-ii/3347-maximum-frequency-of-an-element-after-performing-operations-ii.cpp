class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end()) + k;

        map<int, int> diff;
        unordered_map<int, int> freq;

        // O(N log(N))
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;

            int l = max(nums[i] - k, 0);
            int r = min(nums[i] + k, maxi);

            diff[l]++;
            diff[r + 1]--;

            diff[nums[i]] += 0;
        }

        int ans = INT_MIN;
        int cumSum = 0;
        
        // O(N)
        for (auto it = diff.begin(); it != diff.end(); it++) {
            int target = it->first;
            it->second += cumSum;

            int targetFreq = freq[target];
            int needConversion = it->second - targetFreq;

            int maxPossible = min(needConversion, numOperations);

            ans = max(ans, targetFreq + maxPossible);

            cumSum = it->second;
        }

        return ans;
    }
};