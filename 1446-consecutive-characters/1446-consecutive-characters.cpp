class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int maxLen = 1;
        int len = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                len++;
                maxLen = max(maxLen, len);
            } else {
                len = 1;
            }
        }
        return maxLen;
    }
};