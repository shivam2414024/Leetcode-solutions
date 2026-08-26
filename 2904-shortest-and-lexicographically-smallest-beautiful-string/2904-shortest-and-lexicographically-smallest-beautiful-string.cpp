class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        int minLen = INT_MAX;
        int count = 0;
        int l = 0, r = 0;
        while (r < n) {
            if (s[r] == '1')
                count++;

            while (count > k) {
                if (s[l] == '1')
                    count--;
                l++;
            }

            if (count == k) {

                while (l < r && s[l] == '0')
                    l++;

                int len = r - l + 1;
                string curr = s.substr(l, len);

                if (len < minLen) {
                    minLen = len;
                    ans = curr;
                }

                else if (len == minLen && ans > curr)
                    ans = curr;
            }


            r++;
        }
        return ans;
    }
};