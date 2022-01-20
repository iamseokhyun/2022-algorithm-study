class Solution:
    def getSum(self, a: int, b: int) -> int:
        MASK = 0xffffffff
        
        if not a or not b:
            return a if not b else b
        
        while b:
            a, b = (a ^ b) & MASK, ((a & b) << 1) & MASK
            
        if (a>>31) & 1:
            return ~(a^MASK)
        
        return a
