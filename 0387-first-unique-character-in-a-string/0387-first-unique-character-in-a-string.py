class Solution:
    def firstUniqChar(self, s: str) -> int:
        n = len(s)

        freq = [0] * 26

        for i in range(n):
            freq[ord(s[i]) - ord('a')] += 1

        for i in range(n):
            if freq[ord(s[i]) - ord('a')] == 1:
                return i
        
        return -1
