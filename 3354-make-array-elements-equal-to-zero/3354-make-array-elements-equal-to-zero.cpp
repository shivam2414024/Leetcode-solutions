class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> pref(n, 0);
        vector<int> suf(n, 0);
        pref[0] = nums[0];
        suf[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            pref[i] = nums[i] + pref[i - 1];
            suf[n - 1 - i] = nums[n - 1 - i] + suf[n - 1 - i + 1];
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (pref[i] == suf[i])
                    ans += 2;
                else if (abs(pref[i] - suf[i]) == 1)
                    ans += 1;
            }
        }
        return ans;
    }
};