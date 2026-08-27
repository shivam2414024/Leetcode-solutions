class Solution {
public:
    bool solve(int n, int idx, int open, string& s, vector<vector<int>>& dp) {
        if (idx == n)
            return open == 0;

        if (dp[idx][open] != -1)
            return dp[idx][open];

        bool isValid = false;

        if (s[idx] == '*') {
            isValid |= solve(n, idx + 1, open, s, dp);
            isValid |= solve(n, idx + 1, open + 1, s, dp);
            if (open > 0)
                isValid |= solve(n, idx + 1, open - 1, s, dp);
        } else if (s[idx] == '(') {
            isValid |= solve(n, idx + 1, open + 1, s, dp);
        } else if (open > 0) {
            isValid |= solve(n, idx + 1, open - 1, s, dp);
        }

        return dp[idx][open] = isValid;
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(n, 0, 0, s, dp);
    }
};