class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0] == '0':
            return 0

        dp = [0] * (len(s) + 1)  # dp[i] means the number of ways for s[:i]

        # base case initialization
        dp[0:2] = [1, 1]

        for i in range(2, len(s) + 1):
            # For the last one digit
            if 0 < int(s[i-1:i]) <= 9:  # (0, 9]
                dp[i] += dp[i - 1]
            # For the last two digits
            if 10 <= int(s[i-2:i]) <= 26:  # [10, 26]
                dp[i] += dp[i - 2]
        return dp[-1]  # dp[len(s)]
