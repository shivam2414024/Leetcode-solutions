class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        vector<int> arr(26, 0);
        int maxFreq = 0;
        int num = -1;
        int maxLen = 1;
        while (r < n) {
            arr[s[r] - 'a'] += 1;
            if (maxFreq < arr[s[r] - 'a']) {
                maxFreq = arr[s[r] - 'a'];
                num = s[r] - 'a';
            }
            while (l < r && maxFreq > 2) {
                arr[s[l] - 'a'] -= 1;
                if (num == (s[l] - 'a'))
                    maxFreq--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};