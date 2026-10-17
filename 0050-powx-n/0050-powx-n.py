class Solution:
    def solve(self, x, n):
        if n == 0:
            return 1

        a = self.solve(x, n // 2)
        if n % 2 == 0:
            return a * a
        else:
            return a * a * x

    def myPow(self, x: float, n: int) -> float:
        if n >= 0:
            return self.solve(x, n)
        else:
            return 1 / self.solve(x, n*(-1))
