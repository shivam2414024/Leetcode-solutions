class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)

        max_len = 0
        dict1 = {}
        l = 0
        r = 0

        while r < n:
            if s[r] in dict1:
                if dict1[s[r]] >= l:
                    l = dict1[s[r]] + 1

            max_len = max(max_len, r - l + 1)
            dict1[s[r]] = r
            r+=1

        return max_len
