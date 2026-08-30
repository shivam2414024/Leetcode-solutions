class Solution {
public:
    void solve(int n, vector<int>& nums, vector<int>& arr, set<int>& st,
               int idx, vector<vector<int>>& ans) {
        if (idx == n) {
            ans.push_back(arr);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (st.find(nums[i]) != st.end())
                continue;
            arr.push_back(nums[i]);
            st.insert(nums[i]);
            solve(n, nums, arr, st, idx + 1, ans);
            arr.pop_back();
            st.erase(nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> arr;
        set<int> st;
        solve(n, nums, arr, st, 0, ans);
        return ans;
    }
};