class Solution {
public:
    void solve(int n, int k, int num, int idx, vector<vector<int>>& ans,
               vector<int>& arr) {
        if (idx == k) {
            ans.push_back(arr);
            return;
        }

        if (num > n)
            return;

        arr.push_back(num);
        solve(n, k, num + 1, idx + 1, ans, arr);
        arr.pop_back();
        solve(n, k, num + 1, idx, ans, arr);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> arr;
        solve(n, k, 1, 0, ans, arr);
        return ans;
    }
};