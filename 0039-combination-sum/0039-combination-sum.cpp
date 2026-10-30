class Solution {
public:
    // TC: O(2^t * k) t is target
    // SC: O(k * x) x is the size of the ds
    void solve(int i, vector<int>& candidates, int target,
               vector<vector<int>>& ans, vector<int>& ds) {
        if (i == candidates.size()) {
            if (target == 0)
                ans.push_back(ds);
            return;
        }
        if (candidates[i] <= target) {
            ds.push_back(candidates[i]);
            solve(i, candidates, target - candidates[i], ans, ds);
            ds.pop_back();
        }
        solve(i + 1, candidates, target, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, candidates, target, ans, ds);
        return ans;
    }
};