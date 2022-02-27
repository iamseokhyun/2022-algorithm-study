# Time Limit Exceeded

class Solution:
    
    def strminus(self, finger, splinter):
        if finger[len(finger) - len(splinter):] == splinter:
            return finger[:len(finger) - len(splinter)]
        else:
            return ValueError
    
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        
        combinations = []
        
        def dfs(strsum, index):
            if strsum == '':
                combinations.append(True)
                return
            
            for i in range(0, len(wordDict)):
                try:
                    dfs(self.strminus(strsum, wordDict[i]), i)
                except:
                    continue
                    
        dfs(s, 0)
        
        return True in combinations
