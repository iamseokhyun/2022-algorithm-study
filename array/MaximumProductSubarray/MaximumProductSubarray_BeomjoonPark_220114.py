def find(nums, start, end, neg):
    
    if(start == end):
        return 0
    elif(start + 1 == end):
        return nums[start]
    elif(neg%2 ==0):
        res = 1
        for i in range(end-start):
            res = res*nums[start+i]
        return res
    else:
        neg_cnt = 0
        res = 1
        for i in range(end-start):
            if(nums[start + i] < 0):
                neg_cnt = neg_cnt + 1
            if(neg_cnt == neg):
                break
            res = res * nums[start+i]
        
        
        neg_cnt = 0
        temp = 1
        for j in range(end-start):
            if(nums[end - j -1] < 0):
                neg_cnt = neg_cnt+1
            if(neg_cnt == neg):
                break
            temp = temp * nums[end - j - 1]
        
        
        if (temp > res):
            res = temp
        
        
        return res
        
        
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        l = len(nums)
        neg = 0
        start = 0
        res = nums[0]
        zeroexist = 0
        
        for i in range(l):
            if nums[i]<0:
                neg = neg+1
            if nums[i] == 0:
                zeroexist = 1
                temp = find(nums, start, i, neg)
                if(temp > res):
                    res = temp
                start = i+1
                neg = 0
        
        temp = find(nums, start, l, neg)
        if (temp > res):
            res = temp
            
        if(zeroexist == 1 and res < 0):
            res = 0
            
        return res