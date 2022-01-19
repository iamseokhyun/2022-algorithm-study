def rec(hlist, l, r):
    w = r - l
    if w == 0:
        return 2 * hlist[l-1]
    if w == 1:
        return min(hlist[l], hlist[r])
    
    if hlist[l] > hlist[r]:
        cur = w * hlist[r]
        return max(rec(hlist, l, r-1), cur)
    
    elif hlist[l] < hlist[r]:
        cur = w * hlist[l]
        return max(rec(hlist, l+1, r), cur)
    
    else:
        cur = w * hlist[l]
        return max(rec(hlist, l+1, r-1), cur)



class Solution:
    def maxArea(self, height: List[int]) -> int:
        return rec(height, 0, len(height)-1)
        