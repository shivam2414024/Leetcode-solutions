class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            mp[sum] = i;
        }
        int k = sum - x;
        if(k < 0) return -1;
        int maxLen = INT_MIN;
        int currSum = 0;
        for (int i = 0; i < n; i++) {
            currSum += nums[i];

            if (mp.find(currSum - k) != mp.end()) {
                int idx = mp[currSum - k];
                maxLen = max(maxLen, i - idx);
            }
        }

        return maxLen == INT_MIN ? -1 : n - maxLen;
    }
};