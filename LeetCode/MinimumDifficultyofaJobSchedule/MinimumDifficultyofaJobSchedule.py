class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        if n < d:
            return -1

        dp = [[float('inf')] * n + [0] for _ in range(d + 1)]
        dp[0][n] = 0

        for i in range(1, d + 1):
            for j in range(n - i + 1):
                maxd = 0
                for k in range(j, n - i + 1):
                    maxd = max(maxd, jobDifficulty[k])
                    dp[i][j] = min(dp[i][j], maxd + dp[i - 1][k + 1])

        return dp[d][0]
