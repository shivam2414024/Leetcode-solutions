class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long ans = 0;
        int count = 0;
        if (s[0] == '1')
            count++;
        for (int i = 1; i < n; i++) {
            if (s[i] == '0')
                ans += count;
            else
                count++;
        }
        return ans;
    }
};