class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> diff(n, 0);
        for (auto& it : queries) {
            int l = it[0];
            int r = it[1];
            diff[l] -= 1;
            if (r + 1 < n)
                diff[r+1] += 1;
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
};