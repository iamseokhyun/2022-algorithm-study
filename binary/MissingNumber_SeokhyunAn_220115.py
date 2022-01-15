class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        for i in range(max(nums)):
            try:
                nums.index(i)
            except:
                return(i)
        return max(nums)+1
