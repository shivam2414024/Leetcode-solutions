class Solution:
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        n = len(matrix)
        m = len(matrix[0])

        ans = []
        left = 0
        right = m - 1
        top = 0
        buttom = n - 1

        while top <= buttom and left <= right:

            for i in range(left, right + 1):
                ans.append(matrix[top][i])
            top += 1

            for i in range(top, buttom + 1):
                ans.append(matrix[i][right])
            right -= 1

            if top <= buttom:
                for i in range(right, left - 1, -1):
                    ans.append(matrix[buttom][i])
                buttom -= 1

            if left <= right:
                for i in range(buttom, top - 1, -1):
                    ans.append(matrix[i][left])
                left += 1

        return ans
