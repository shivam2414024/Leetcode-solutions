class Solution:
    def calculateScore(self, a: int, b: int) -> int:
        s1 = 0
        s2 = 0
        for i in range(0, 32):
            s1 += 1 if (a & (1 << i)) else 0
            s2 += 1 if (b & (1 << i)) else 0

        if s1 >= s2:
            return s1 * s2

        return s2 // s1
