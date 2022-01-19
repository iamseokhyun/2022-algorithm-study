class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        res = []
        newlist = nums[:]
        newlist.sort()
        l = len(nums)
        
        for i in range(l):
            if(i != 0 and newlist[i] == newlist[i-1]):
                continue
            
            j = i + 1
            k = l - 1
            
            while j < k:
                    
                a = newlist[j] + newlist[k]
                
                if(a == -newlist[i]):
                    res.append([newlist[i], newlist[j], newlist[k]])
                    
                    k = k - 1
                    while(newlist[k] == newlist[k+1] and j < k):
                        k = k-1
                    
                    j = j + 1
                    while(newlist[j] == newlist[j-1] and j < k):
                        j = j + 1
                    
                elif(a > -newlist[i]):
                    k = k - 1
                    while(newlist[k] == newlist[k+1] and j < k):
                        k = k-1
                else:   # a < -newllist
                    j = j + 1
                    while(newlist[j] == newlist[j-1] and j < k):
                        j = j + 1
                
        return res