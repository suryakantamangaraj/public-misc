class Solution:
    def imageSmoother(self, img):
        m, n = len(img), len(img[0])
        res = [[0]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                count = 0
                for r in (-1, 0, 1):
                    for c in (-1, 0, 1):
                        ni, nj = i + r, j + c
                        if 0 <= ni < m and 0 <= nj < n:
                            res[i][j] += img[ni][nj]
                            count += 1
                res[i][j] //= count
        return res
