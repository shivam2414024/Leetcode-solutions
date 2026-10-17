class Solution:
    def runningSum(self, nums: list[int]) -> list[int]:
        ans = []
        sum = 0
        for i in nums:
            sum += i
            ans.append(sum)
        return ans
