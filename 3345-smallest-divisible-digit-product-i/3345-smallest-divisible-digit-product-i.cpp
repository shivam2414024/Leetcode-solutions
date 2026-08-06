class Solution {
public:
    bool check(int x, int t) {
        int prod = 1;
        while (x != 0) {
            prod = prod * (x % 10);
            if (prod == 0)
                break;
            x /= 10;
        }
        if (prod % t == 0)
            return true;
        return false;
    }
    int smallestNumber(int n, int t) {
        int ans = n;
        for (int i = n; i <= 100; i++) {
            if (check(i, t)) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};