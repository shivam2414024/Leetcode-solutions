class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            float x = 0, y = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0)
                    x++;
                else
                    y++;
                if (y > 0 && (x / y) <= (float)a / b)
                    ans++;
                // if (y > 0 && 1LL * x * b <= 1LL * a * y)
                //     ans++;
            }
        }
        return ans;
    }
};