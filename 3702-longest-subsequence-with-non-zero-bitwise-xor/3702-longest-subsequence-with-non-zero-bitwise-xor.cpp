class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                flag = true;
                break;
            }
        }
        if (!flag)
            return 0;
        int XOR = 0;
        for (int i = 0; i < n; i++) {
            XOR ^= nums[i];
        }
        if (XOR != 0)
            return n;
        return n - 1;
    }
};