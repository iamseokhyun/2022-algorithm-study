import math as m

class Solution:
    def climbStairs(self, n: int) -> int:
        _2step = n // 2
        _sum = 0
        for i in range(_2step+1):
            _sum += m.factorial(n-i) // ((m.factorial(i))*m.factorial(n-2*i))
        return _sum
