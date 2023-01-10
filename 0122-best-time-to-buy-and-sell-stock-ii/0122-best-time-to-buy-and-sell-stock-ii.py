class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        profit = 0
        for i in range(0,n-1):
            if prices[i] < prices[i+1]:
                profit += prices[i+1] - prices[i]
        return profit
                
        