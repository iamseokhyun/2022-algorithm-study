class Solution:
    def getSum(self, a: int, b: int) -> int:
        res = 0
        addover = 0
        
        
        for i in range(12):
            base = 2**i
            itha = a & base
            ithb = b & base
            
            if (itha ^ ithb == base):   # they are different
                if(addover == 0):
                    res = res | base
                else:
                    continue
                    
            else:                       # they are same
                if addover == 1:
                    res = res | base
                    
                
                if(itha == base):
                    addover = 1
                else:
                    addover = 0
                    
        neg = -1 << 11
        if res > 2000:
            res = res | neg
        return res