class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1)
            return true;
        long long prod = 1;
        while (prod <= n) {
            if (prod == n)
                return true;
            prod *= 4;
        }
        return false;
    }
};