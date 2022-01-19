def binsearch(alist, item):
    first = 0
    last = len(alist) - 1
    found = False

    while first<=last and not found:
        index = 0
        mid = (first + last)//2
        if alist[mid] == item:
            index = mid
            found = True
        else:
            if item < alist[mid]:
                last = mid-1
            else:
                first = mid+1
    if found == False:
        index = -1
    return index

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        l = len(nums)
        newlist = nums[:]
        newlist.sort()
        for i in range(l):
            num1 = newlist[i]
            num2 = target - num1
            if num1 == num2:
                if newlist[i+1] != num1:
                    newlist[i] = newlist[i+1]
                else:
                    newlist[i] = newlist[i-1]

                    # remember, the sort method in python uses nlogn method!
            j = binsearch(newlist, num2)
            if j != -1:
                break
            newlist[i] = num1

        for k in range(l):
            if num1 == nums[k]:
                x = k
        for k in range(l):
            if num2 == nums[k]:
                if x != k:
                    y = k
        return [min(x,y), max(x,y)]
