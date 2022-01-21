# building up from the bottom
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        reslist = []
        for i in range(target+1):
            reslist.append(0)
        
        for i in range(target+1):
            for j in range(len(nums)):
                if(i < nums[j]):
                    continue
                elif(i == nums[j]):
                    reslist[i] = reslist[i] + 1
                else:
                    reslist[i] = reslist[i] + reslist[i - nums[j]]
                    
        
        return reslist[-1]