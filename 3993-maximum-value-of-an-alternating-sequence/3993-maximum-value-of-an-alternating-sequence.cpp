class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n == 1)
            return s;
        long long p = n/2;
        return s + p * 1LL * (m-1) + 1;
    }
};