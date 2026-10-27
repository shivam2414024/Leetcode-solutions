class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        ans = ["#" * n for _ in range(m)]

        ans[0] = "." * n

        for i in range(1, m):
            ans[i] = ans[i][:n-1] + "."

        return ans
