class Solution:
    def reverseBits(self, n: int) -> int:
        res = n
        for i in range(16):
            ind1 = 2**i
            ind2 = 2**(31-i)
            
            num1 = ind1 & n
            num2 = ind2 & n
            
            if (num1 << (31-i)) != (num2 << i):
                if num1 == ind1:
                    res = res - ind1 + ind2
                else:
                    res = res + ind1 - ind2
        
        return res