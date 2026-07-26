class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi1 = INT_MIN, maxi2 = INT_MIN, maxi3 = INT_MIN;
        int mini1 = INT_MAX, mini2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (maxi1 < nums[i]) {
                maxi3 = maxi2;
                maxi2 = maxi1;
                maxi1 = nums[i];
            } else if (maxi2 < nums[i]) {
                maxi3 = maxi2;
                maxi2 = nums[i];
            } else if (maxi3 < nums[i]) {
                maxi3 = nums[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (mini1 > nums[i]) {
                mini2 = mini1;
                mini1 = nums[i];
            } else if (mini2 > nums[i]) {
                mini2 = nums[i];
            }
        }
        return max(maxi1 * maxi2 * maxi3, mini1 * mini2 * maxi1);
    }
};