class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        max_sum = float("-inf")
        sum = 0

        for i in nums:
            sum += i
            max_sum = max(max_sum, sum)
            if sum < 0:
                sum = 0

        return max_sum
