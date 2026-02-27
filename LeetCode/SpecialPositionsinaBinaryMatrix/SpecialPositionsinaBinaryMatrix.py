class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        row_sum = [0]*m
        col_sum = [0]*n

        # Calculate the sum of each row and column
        for i in range(m):
            for j in range(n):
                row_sum[i] += mat[i][j]
                col_sum[j] += mat[i][j]

        # Check each cell if it's a special position
        special_positions = 0
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1 and row_sum[i] == 1 and col_sum[j] == 1:
                    special_positions += 1

        return special_positions
