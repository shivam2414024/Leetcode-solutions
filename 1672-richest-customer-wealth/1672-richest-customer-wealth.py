class Solution:
    def maximumWealth(self, accounts: list[list[int]]) -> int:
        n = len(accounts)

        max_sum = 0

        for i in range(0, n):
            s = sum(accounts[i])
            max_sum = max(max_sum, s)

        return max_sum
