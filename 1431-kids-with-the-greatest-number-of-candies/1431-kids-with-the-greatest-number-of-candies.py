class Solution:
    def kidsWithCandies(self, candies: list[int], extraCandies: int) -> list[bool]:
        size = len(candies)
        maxi = max(candies)
        ans = [False]*size
        for i in range(size):
          if(candies[i] + extraCandies >= maxi):
            ans[i] = True
        return ans