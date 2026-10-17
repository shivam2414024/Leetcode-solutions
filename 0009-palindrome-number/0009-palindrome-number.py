class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        y = x
        num = 0
        while y != 0:
            num = (10 * num) + (y%10)
            y//=10
        if num == x:
          return True
        return False