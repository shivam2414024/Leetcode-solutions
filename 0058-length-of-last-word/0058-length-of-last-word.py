class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()
        n = len(s)

        i = -1
        l = 0
        while i >= (-1*n) and s[i] != " ":
            l+=1
            i-=1
        
        return l
