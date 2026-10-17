class Solution:
    def solve(self, n, dp):
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1

        if dp[n] != -1:
            return dp[n]

        dp[n] = self.solve(n - 1, dp) + self.solve(n - 2, dp) + self.solve(n - 3, dp)

        return dp[n]

    def tribonacci(self, n: int) -> int:
        dp = [-1] * (n + 1)

        return self.solve(n, dp)
