class Solution {
public:
    void solve(int n, vector<int>& nums, vector<int>& arr, int idx,
               vector<vector<int>>& ans, set<vector<int>>& st) {
        if (arr.size() >= 2) {
            if (st.find(arr) == st.end()) {
                ans.push_back(arr);
                st.insert(arr);
            }
        }
        if (idx == n)
            return;
        for (int i = idx; i < n; i++) {
            if (!arr.empty() && arr.back() > nums[i])
                continue;
            arr.push_back(nums[i]);
            solve(n, nums, arr, i + 1, ans, st);
            arr.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> arr;
        solve(n, nums, arr, 0, ans, st);
        return ans;
    }
};