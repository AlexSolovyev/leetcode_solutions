class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)

        if k == 0 or n < 2:
            return 0

        if 2 * k >= n: 
            return sum(max(0, prices[i] - prices[i-1]) for i in range(1, n))
        
        dp = [0]* n
        for i in range(k):
            val = 0
            for j in range(1, n): 
                val = max(val + prices[j] - prices[j-1], dp[j]) 
                dp[j] = max(dp[j-1], val)
        return dp[-1]
