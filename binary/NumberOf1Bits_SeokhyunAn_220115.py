class Solution:
    def hammingWeight(self, n: int) -> int:
        self.cnt = 0
        for i in list(str(bin(n)))[2:]:
            if i == '1':
                self.cnt += 1
        return self.cnt
