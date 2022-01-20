class Solution:
    def reverseBits(self, n: int) -> int:
        n = bin(n)[2:]
        n = '0'*(32-len(n)) + n
        return int(n[::-1], 2)
