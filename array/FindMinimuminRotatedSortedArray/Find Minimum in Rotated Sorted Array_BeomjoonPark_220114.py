def rec(nums, start, end, ref_val):
    l = end - start
    if l == 1:
        return nums[start]
    elif l == 2:
        if nums[start] > nums[start+1]:
            return nums[start+1]
        return nums[start]
    
    mid = start + l//2
    
    if nums[mid] < ref_val:
        return rec(nums, start, mid+1, ref_val)
    else:
        return rec(nums, mid, end, ref_val)
    
class Solution:
    def findMin(self, nums: List[int]) -> int:
        l = len(nums)
        ref_ind = l//2
        ref_val = nums[ref_ind]
        if(ref_val > nums[-1]):
            # value in right
            return rec(nums, ref_ind+1, l, ref_val)
            
            
        elif(ref_val < nums[-1]):
            # value in left
            return rec(nums, 0, ref_ind+1, ref_val)
        else:
            #l == 2
            if ref_val < nums[0]:
                return ref_val
            else:
                return nums[0]