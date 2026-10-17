class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        n = len(nums)
        k = 1
        freq = 1
        for i in range(1, n):
            if nums[i] == nums[i - 1] and freq == 1:
                nums[k] = nums[i]
                k += 1
                freq += 1
            elif nums[i] != nums[i - 1]:
                nums[k] = nums[i]
                k += 1
                freq = 1
        return k
