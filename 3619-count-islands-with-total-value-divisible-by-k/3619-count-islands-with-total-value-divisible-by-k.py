class Solution:
    def dfs(self, m, n, grid, r, c, d_row, d_col):
        total = grid[r][c]
        grid[r][c] = 0

        for i in range(4):
            _r = r + d_row[i]
            _c = c + d_col[i]
            if _r >= 0 and _r < m and _c >= 0 and _c < n and grid[_r][_c] != 0:
                total += self.dfs(m, n, grid, _r, _c, d_row, d_col)

        return total

    def countIslands(self, grid: List[List[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])

        count = 0
        d_row = [-1, 0, 1, 0]
        d_col = [0, -1, 0, 1]
        for i in range(m):
            for j in range(n):

                if grid[i][j] != 0:
                    total = self.dfs(m, n, grid, i, j, d_row, d_col)
                    if total % k == 0:
                        count += 1

        return count
