class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n == 1: 
            return True
        prod = 1
        while prod <= n:
            if prod == n:
                return True
            prod *= 3
        return False