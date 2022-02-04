class Solution:
    def rob(self, nums: List[int]) -> int:
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