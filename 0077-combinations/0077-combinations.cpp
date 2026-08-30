class Solution {
public:
    void solve(int n, int k, int num, int idx, vector<vector<int>>& ans,
               vector<int>& arr) {
        if (idx == k) {
            ans.push_back(arr);
            return;
        }

        for (int i = num; i <= n; i++) {
            arr.push_back(i);
            solve(n, k, i + 1, idx + 1, ans, arr);
            arr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> arr;
        solve(n, k, 1, 0, ans, arr);
        return ans;
    }
};