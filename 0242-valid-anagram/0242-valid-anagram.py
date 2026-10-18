class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        dict1 = {}

        for i in s:
            if i not in dict1:
                dict1[i] = 1
            else:
                dict1[i] += 1

        for i in t:
            if i not in dict1:
                return False
            else:
                dict1[i] -= 1

        for i in dict1.values():
            if i != 0:
                return False

        return True
