maxint = 2**31

def rec(coins, amount, ans):
    if amount in ans:
        return ans[amount]
    elif amount in coins:
        ans[amount] = 1
        return 1

    temp = maxint
    for c in coins:
        if amount > c:
            t = rec(coins, amount - c, ans)
            if temp > t:
                temp = t + 1
    
    ans[amount] = temp
    return temp
        

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
        
        ans = {}
        
        res = rec(coins, amount, ans)
        
        if res > amount:
            return -1
        else:
            return res