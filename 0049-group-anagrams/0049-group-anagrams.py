class Solution:
    def sortString(self, s):
        s = sorted(s)
        return "".join(s)

    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        dict1 = {}

        for i in strs:
            t = self.sortString(i)
            if t not in dict1:
                dict1[t] = [i]
            else:
                dict1[t].append(i)

        return list(dict1.values())
