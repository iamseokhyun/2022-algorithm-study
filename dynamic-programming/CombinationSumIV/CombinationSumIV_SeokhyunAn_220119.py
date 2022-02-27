# Time Limit Exceeded

import math as m

class Solution:
    def numpermut(self, nums):
        overlap = []
        for i in list(set(nums)):
            overlap.append(m.factorial(nums.count(i)))
        return m.factorial(len(nums)) // self.listmul(overlap)
    
    def listmul(self, nums):
        _to_return = 1
        for i in nums:
            _to_return *= i
        return _to_return
    
    def combinationSum4(self, nums: List[int], target: int) -> int:
        if target == 0:
            return 0
        
        combinations = []
        
        def dfs(csum, index, path):
            if csum < 0:
                return
            
            if csum == 0:
                combinations.append(path)
                return
            
            for i in rangeindex, len(nums)):
                dfs(csum - nums[i], i, path + [nums[i]])
        
        dfs(target, 0, [])
        
        if combinations == []:
            return 0
        else:
            return sum(list(map(self.numpermut, combinations)))(
