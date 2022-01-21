class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        res = []
        for i in range(len(nums)):
            if (len(res) == 0):
                res.append([nums[0]])
            else:
                for j in range(len(res)):
                    if res[j][j] >= nums[i]:
                        res[j][j] = nums[i]
                        break
                        
                if res[-1][-1] < nums[i]:
                    temp = res[-1][:]
                    res.append(temp)
                    res[-1].append(nums[i])
        
        return len(res)