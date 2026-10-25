class Solution:
    def peakValleyDifference(self, nums: list[int]) -> int:
        n = len(nums)
        peak_sum = 0
        for i in range(1, n - 1):
            if nums[i] > nums[i - 1] and nums[i] > nums[i + 1]:
                peak_sum += nums[i]
        valley_sum = 0
        for i in range(1, n - 1):
            if nums[i] < nums[i - 1] and nums[i] < nums[i + 1]:
                valley_sum += nums[i]

        return peak_sum - valley_sum
