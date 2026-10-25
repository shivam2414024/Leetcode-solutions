class Solution:
    def countSubarrays(self, nums: list[int], minK: int, maxK: int) -> int:
        n = len(nums)
        l = 0
        ans = 0

        for i in range(0, n):
            if minK <= nums[i] <= maxK:
                l += 1
                ans += l
            else:
                l = 0

        return ans
