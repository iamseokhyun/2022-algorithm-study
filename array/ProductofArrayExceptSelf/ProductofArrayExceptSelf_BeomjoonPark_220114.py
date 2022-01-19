class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        l = len(nums)
        
        lmul = 1
        rmul = 1
        
        output = []
        output.append(1)
        
        for i in range(l-1):
            lmul = lmul * nums[i]
            output.append(lmul)
        for i in range(l-1):
            rmul = rmul * nums[l-i-1]
            output[l-i-2] = output[l-i-2] * rmul
        
        return output