class Solution:
    def buyChoco(self, prices, money):
        prices.sort()
        for i in range(len(prices) - 1):
            for j in range(i + 1, len(prices)):
                if prices[i] + prices[j] <= money:
                    money -= prices[i] + prices[j]
                    return money
        return money
