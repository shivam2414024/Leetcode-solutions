class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        n = len(nums)
        count = 1
        k = 1
        for i in range(1, n):
            if nums[i] != nums[i - 1]:
                nums[k] = nums[i]
                k += 1
                count += 1
        return count
