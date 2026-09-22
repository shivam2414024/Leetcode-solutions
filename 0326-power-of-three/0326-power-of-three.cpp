class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1)
            return true;
        long long prod = 1;
        while (prod <= n) {
            if (prod == n)
                return true;
            prod *= 3;
        }
        return false;
    }
};