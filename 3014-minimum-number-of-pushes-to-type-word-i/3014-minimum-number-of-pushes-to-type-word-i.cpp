class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if (n <= 8)
            return n;
        int ans = 0;
        int i = 1;
        while (n != 0) {
            if (n >= 8) {
                ans += (i * 8);
                n -= 8;
            } else {
                ans += (i * n);
                n = 0;
            }
            i++;
        }
        return ans;
    }
};