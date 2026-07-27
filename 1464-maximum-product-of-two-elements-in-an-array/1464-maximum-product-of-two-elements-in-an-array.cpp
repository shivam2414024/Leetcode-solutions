class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        int prod = (nums[0]-1) * (nums[1] -1);
        return prod;
    }
};