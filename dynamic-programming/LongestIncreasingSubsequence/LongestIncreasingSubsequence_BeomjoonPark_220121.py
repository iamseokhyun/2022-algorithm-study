def binsearch(maxvals, val):
    r = len(maxvals)
    l = 0 
    m = (l + r)//2
    
    while(not(val <= maxvals[m] and (m == 0 or val > maxvals[m-1]))):
        if maxvals[m] > val:
            r = m-1
            m = (l + r)//2
        else:
            l = m+1
            m = (l + r)//2
    return m

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        res = []
        maxvals = []
        
        for i in range(len(nums)):
            if (len(res) == 0):
                res.append([nums[0]])
                maxvals.append(nums[0])
            else:
                if res[-1][-1] < nums[i]:
                    temp = res[-1][:]
                    res.append(temp)
                    res[-1].append(nums[i])
                    maxvals.append(nums[i])
                else:
                    k = binsearch(maxvals, nums[i])
                    res[k][-1] = nums[i]
                    maxvals[k] = nums[i]
        
        return len(res)