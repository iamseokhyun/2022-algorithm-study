class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        l1 = len(text1)
        l2 = len(text2)
        
        lcs = []
        res = 0
        
        for i in range(l1):
            t = []
            for j in range(l2):
                t.append(0)
            lcs.append(t)
        
        for i in range(l1):
            used = 0
            for j in range(l2):
                
                if(lcs[i-1][j] < lcs[i][j-1]):
                    lcs[i][j] = lcs[i][j-1]
                elif(lcs[i-1][j] > lcs[i][j-1]):
                    lcs[i][j] = lcs[i-1][j]
                    used = 0
                else:
                    if used == 0 and text1[i] == text2[j]:
                        lcs[i][j] = lcs[i-1][j] + 1
                        used = 1
                        if res < lcs[i][j]:
                            res = lcs[i][j]
                    else:
                        lcs[i][j] = lcs[i-1][j]
                        used = 0
                
        return res