class Solution {
public:
    string check(string s1, string s2) {
        int i = 0, j = 0;
        while (i < s1.size()) {
            if (s1[i] != s2[j]) {
                if (s1[i] < s2[j])
                    return s1;
                else if (s1[i] > s2[j])
                    return s2;
            }
            i++;
            j++;
        }
        return s1;
    }
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int minLen = 0;
        string ans = "";
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '1')
                    count++;
                if (count == k) {
                    if (k == 1)
                        return "1";
                    if (minLen == 0) {
                        minLen = j - i + 1;
                        ans = s.substr(i, minLen);
                        break;
                    } else {
                        if (minLen > j - i + 1) {
                            minLen = j - i + 1;
                            ans = s.substr(i, minLen);
                        } else if (minLen == j - i + 1) {
                            ans = check(ans, s.substr(i, j - i + 1));
                        }
                        break;
                    }
                }
            }
        }
        return ans;
    }
};