class Solution:
    def canJump(self, nums: List[int]) -> bool:
        l = len(nums)
        if l == 1:
            return True
        
        i = 0
        maxindex = 0
        while (i < l-1) and (i >= 0):
            if nums[i] == 0:
                i = i - 1 
            else:
                temp = i + nums[i]
                if temp > maxindex:
                    i = temp
                    maxindex = temp
                else:
                    i = i - 1
        if i == -1:
            return False
        return True