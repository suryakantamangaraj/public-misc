class Solution:
    def maxScore(self, s: str) -> int:
        # Initialize counts of ones and zeros
        ones = s.count('1')
        zeros = 0
        max_score = 0

        # Iterate over the string, excluding the last character
        for char in s[:-1]:
            if char == '0':
                zeros += 1
            else:
                ones -= 1

            # Update max_score
            max_score = max(max_score, zeros + ones)

        return max_score
