class Solution:
    def dfs(self, grid, r, c, n, m):
        if r >= n or r < 0 or c >= m or c < 0:
            return False

        if grid[r][c] == 1:
            return True

        grid[r][c] = 1

        left = self.dfs(grid, r, c - 1, n, m)
        right = self.dfs(grid, r, c + 1, n, m)
        top = self.dfs(grid, r - 1, c, n, m)
        bottom = self.dfs(grid, r + 1, c, n, m)

        return left and right and top and bottom

    def closedIsland(self, grid: list[list[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        count = 0

        for i in range(n):
            for j in range(m):

                if grid[i][j] == 0:
                    if self.dfs(grid, i, j, n, m) == True:
                        count += 1

        return count
