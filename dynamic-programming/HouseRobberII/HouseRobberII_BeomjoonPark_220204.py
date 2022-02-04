def normrob(nums):
    l = len(nums)
    ans = []
    for i in range(l):
        if i == 0:
            ans.append(nums[i])
        elif i == 1:
            ans.append(max(nums[0], nums[1]))
        else:
            ans.append(max(ans[i-2]+nums[i], ans[i-1]))
    return ans[-1]
    
class Solution:
    def rob(self, nums: List[int]) -> int:
        l = len(nums)
        if l == 1:
            return nums[0]
        
        lst1 = nums[0:l-1]
        lst2 = nums[1:l]
        
        return max(normrob(lst1), normrob(lst2))