class Solution {
public:
    int count(vector<int>& arr) {
        int n = arr.size();
        vector<int> pref(n);
        pref[0] = arr[0];
        for (int i = 1; i < n; i++) {
            pref[i] = gcd(pref[i - 1], arr[i]);
        }
        vector<int> suff(n);
        suff[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = gcd(suff[i + 1], arr[i]);
        }
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (pref[i] == suff[i + 1])
                count++;
        }
        return count;
    }
    int maxValidSplits(vector<int>& nums) {
        int m = nums.size();
        int ans = count(nums);
        for (int i = 0; i < m; i++) {
            vector<int> arr;
            for (int j = 0; j < m; j++) {
                if (i == j)
                    continue;

                arr.push_back(nums[j]);
            }
            ans = max(ans, count(arr));
        }

        return ans;
    }
};