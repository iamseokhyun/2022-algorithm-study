def rec(nums, start, end, val):
    l = end - start
    if l == 1:
        if nums[start] == val:
            return start
        return -1
    elif l == 2:
        if nums[start] == val:
            return start
        elif nums[start + 1] == val:
            return start+1
        else:
            return -1
    
    mid = start + l//2
    
    if nums[mid] == val:
        return mid
    
    if nums[mid] < nums[end-1]:
        if(nums[mid] < val and val <= nums[end-1]):
            return rec(nums, mid+1, end, val)
        else:
            return rec(nums, start, mid, val)
    else:
        if(nums[start] <= val and val < nums[mid]):
            return rec(nums, start, mid, val)
        else:
            return rec(nums, mid+1, end, val)


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        return rec(nums, 0, len(nums), target)