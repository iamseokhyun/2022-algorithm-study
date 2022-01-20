class Solution:
    def countBits(self, n: int) -> List[int]:
        ind = 0
        res = [0]
        
        for i in range(1, n+1):
            if(i == 2**ind):
                res.append(1)
                ind = ind + 1
            else:
                res.append(res[i - (2**(ind-1))] + 1)
        
        return res
        