class Solution:
    def numDecodings(self, s: str) -> int:
        l = len(s)
        ans = []
        
        for i in range(l):
            ans.append(0)
            
            if i == 0:
                if s[i] != '0':
                    ans[i] = 1
                continue
                
            if i == 1:
                if s[i] != '0':
                    ans[i] += ans[i-1]
                
                t = int(s[i-1]+s[i])
                if 9 < t and t < 27:
                    ans[i] += 1
                continue
            
            
            if s[i] != '0':
                ans[i] += ans[i-1]
                
            t = int(s[i-1]+s[i])
            if 9 < t and t < 27:
                ans[i] += ans[i-2]
            
            
        return ans[-1]