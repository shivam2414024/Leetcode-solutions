class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0)
            return 0;
        vector<long long> a(31, 0);
        a[0] = 1;
        for (int i = 1; i < 31; i++) {
            a[i] = 2 * a[i - 1] + 1;
        }
        int count = 0;
        int sign = 1;
        for (int i = 30; i >= 0; i--) {
            int ith_bit = ((1 << i) & n);
            if (ith_bit == 0)
                continue;
            if (sign > 0) {
                count += a[i];
            } else {
                count -= a[i];
            }
            sign = sign * (-1);
        }
        return count;
    }
};