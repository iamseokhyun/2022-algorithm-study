# Time Limit Exceeded

class Solution:
    def coinChange(self, coins, amount):
        combinations = []
        
        def dfs(csum, index, path):
            if csum < 0:
                return
            
            if csum == 0:
                combinations.append(path)
                return
            
            for i in range(index, len(coins)):
                dfs(csum - coins[i], i, path + [coins[i]])
        
        dfs(amount, 0, [])
        
        if combinations == []:
            return -1
        else:
            return min(list(map(len, combinations)))
