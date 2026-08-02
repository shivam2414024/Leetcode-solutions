class Solution {
public:
    // TC: O(2^2n)  SC: O(2n)
    void solve(string& s, int n, vector<string>& ans, int open, int close) {
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }
        if (open < n) {
            s.push_back('(');
            solve(s, n, ans, open + 1, close);
            s.pop_back();
        }
        if (close < open) {
            s.push_back(')');
            solve(s, n, ans, open, close + 1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        int open = 0, close = 0;
        solve(s, n, ans, open, close);
        return ans;
    }
};