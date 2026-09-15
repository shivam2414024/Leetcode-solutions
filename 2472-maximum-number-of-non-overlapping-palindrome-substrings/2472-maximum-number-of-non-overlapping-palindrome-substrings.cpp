class Solution {
public:
    int solve(int n, string& s, int k, int i, int j,
              vector<vector<int>>& isPalindrome, vector<vector<int>>& dp) {
        if (i >= n || j >= n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (isPalindrome[i][j]) {
            int take = 1 + solve(n, s, k, j + 1, j + k, isPalindrome, dp);
            int grow = solve(n, s, k, i, j + 1, isPalindrome, dp);
            int slide = solve(n, s, k, i + 1, j + 1, isPalindrome, dp);

            return dp[i][j] = max({take, grow, slide});
        }

        int grow = solve(n, s, k, i, j + 1, isPalindrome, dp);
        int slide = solve(n, s, k, i + 1, j + 1, isPalindrome, dp);

        return dp[i][j] = max(grow, slide);
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1)
            return n;

        vector<vector<int>> isPalindrome(n + 1, vector<int>(n + 1));

        for (int L = 1; L <= n; L++) {
            for (int i = 0; i + L <= n; i++) {
                int j = i + L - 1;

                if (i == j)
                    isPalindrome[i][j] = 1;
                else if (i + 1 == j)
                    isPalindrome[i][j] = (s[i] == s[j]);
                else
                    isPalindrome[i][j] =
                        (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(n, s, k, 0, k - 1, isPalindrome, dp);
    }
};