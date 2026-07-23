class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        while (k >= sum) {
            k -= sum;
        }
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (k < chalk[i]) {
                ans = i;
                break;
            } else {
                k -= chalk[i];
            }
        }
        return ans;
    }
};