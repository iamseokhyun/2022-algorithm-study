class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        l = len(nums)
        s = 0
        bottom = 0
        res = nums[0]
        
        for i in range(l):
            s = s + nums[i]
            
            temp = s - bottom
            if (res < temp):
                res = temp
                
            if (s < bottom):
                bottom = s
                    
        return res