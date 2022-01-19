class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        
        '''
        # roughest way to do
        l = len(nums)
        newnums = nums[:]
        for i in range(l):
            num = newnums.pop(0)
            if num in newnums:
                return True
        return False
        '''
        
        # another naive way
        l = len(nums)
        newnums = nums[:]
        newnums.sort()
        for i in range(l-1):
            if newnums[i] == newnums[i+1]:
                return True
        return False
        