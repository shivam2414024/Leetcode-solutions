class Solution {
public:
    int digit_sum(int num) {
        int sum = 0;
        while (num != 0) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<tuple<int, int, int>> t;
        for (int i = 0; i < n; i++) {
            int s = digit_sum(nums[i]);
            t.push_back({s, nums[i], i});
        }
        sort(t.begin(), t.end());
        vector<bool> vis(n, false);
        int cycle = 0;
        for (int i = 0; i < n; i++) {
            int idx = get<2>(t[i]);
            if (!vis[i]) {
                vis[i] = true;
                while (i != idx) {
                    vis[idx] = true;
                    idx = get<2>(t[idx]);
                }
                cycle++;
            }
        }
        return n - cycle;
    }
};