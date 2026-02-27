class Solution:
    def findSpecialInteger(self, arr):
        n = len(arr)
        count = 1
        for i in range(1, n):
            if arr[i] == arr[i-1]:
                count += 1
                if count > n / 4:
                    return arr[i]
            else:
                count = 1
        return arr[0]
