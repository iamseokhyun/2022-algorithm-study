class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        
        '''
        # the roughest way to write
        temp = 0
        l = len(prices)
        for i in range(l):
            for j in range(i+1, l):
                temp = max( temp, prices[j]-prices[i])
                
        return temp
        '''
        
        '''
        # my idea making an array
        
        l = len(prices)
        reverselist = []
        temp = 0
        M = 0
        i = 0
        for c in range(l):
            
            reverselist.append(prices[l-c-1])
            M = max(reverselist[i], M)
            if M == reverselist[i]:
                reverselist = [M]
                i = 1
            else:
                temp = max(temp, M-reverselist[i])
                i = i + 1
        return temp
        '''
        # thinking that the array is actually not nessessary
        # and making the algorithm to save the small value 
        l = len(prices)
        temp = 0
        m = 10**4 + 1
        for c in range(l):
            
            if m >= prices[c]:
                m = prices[c]
            else:
                t2 = prices[c] - m
                if t2 > temp:
                    temp = t2
        return temp
        