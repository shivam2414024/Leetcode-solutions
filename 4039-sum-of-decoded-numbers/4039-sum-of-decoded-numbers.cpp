class Solution {
public:
    int MOD = 1e9 + 7;
    pair<long long, long long> solve(long long width, long long d) {
        string s = to_string(d);
        long long x = 0;
        int i = 0;
        while (i < width) {
            x = (x * 10) + (s[i] - '0');
            i++;
        }
        long long y = 0;
        while (i < s.size()) {
            y = (y * 10) + (s[i] - '0');
            i++;
        }

        return {x, y};
    }
    long long power(long long x, long long y) {
        long long res = 1;
        while (y > 0) {
            if (y & 1)
                res = (res * x) % MOD;

            x = (x * x) % MOD;
            y /= 2;
        }
        return res;
    }
    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long width = nums[i] % 10;
            long long d = nums[i] / 10;

            auto [x, y] = solve(width, d);
            ans = (ans + power(x, y)) % MOD;
        }

        return ans % MOD;
    }
};