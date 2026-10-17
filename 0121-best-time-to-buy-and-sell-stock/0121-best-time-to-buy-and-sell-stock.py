class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        profit = 0
        mini = prices[0]

        for i in prices:
            profit = max(profit, i - mini)
            mini = min(mini, i)

        return profit
