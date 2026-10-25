class Solution:
    def max_digit(self, num):
        arr = []
        while num != 0:
            digit = num % 10
            arr.append(digit)
            num //= 10
        arr.sort(reverse=True)
        for i in range(len(arr)):
            num = (10 * num) + arr[i]
        return num

    def maximizeSum(self, nums: list[int], k: int) -> int:
        n = len(nums)
        arr = []
        diff = {}
        for i in range(n):
            n_num = self.max_digit(nums[i])
            arr.append(n_num)
            diff[i] = n_num - nums[i]

        diff = dict(sorted(diff.items(), key=lambda x: x[1], reverse=True))

        ans = 0

        for key, val in diff.items():
            if k != 0:
                ans += arr[key]
                k -= 1
            else:
                ans += nums[key]

        return ans
