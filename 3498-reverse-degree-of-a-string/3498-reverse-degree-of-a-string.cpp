class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = sum + (('z' - s[i] + 1) * (i + 1));
        }
        return sum;
    }
};