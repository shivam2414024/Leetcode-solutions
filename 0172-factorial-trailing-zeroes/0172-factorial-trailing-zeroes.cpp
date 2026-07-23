class Solution {
public:
    // TC : O(log5(n))
    int trailingZeroes(int n) {
        int count = 0;
        long long i = 5;
        while (n / i > 0) {
            count += (n / i);
            i = i * 5;
        }
        return count;
    }
};