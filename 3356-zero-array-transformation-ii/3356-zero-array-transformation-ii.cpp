class Solution {
public:
    bool check(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n, 0);
        for (int i = 0; i < k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            diff[l] -= val;
            if (r + 1 < n) {
                diff[r + 1] += val;
            }
        }
        for (int i = 1; i < n; i++) {
            diff[i] = diff[i] + diff[i - 1];
        }
        for (int i = 0; i < n; i++) {
            if ((nums[i] + diff[i]) > 0)
                return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int flag = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                flag = 0;
                break;
            }
        }
        if (flag)
            return 0;
        int m = queries.size();
        int ans = -1;
        int l = 1, r = m;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(nums, queries, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};