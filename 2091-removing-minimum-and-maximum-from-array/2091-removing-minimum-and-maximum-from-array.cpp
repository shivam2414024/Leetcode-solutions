class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        int min_idx = min_element(nums.begin(), nums.end()) - nums.begin();
        int max_idx = max_element(nums.begin(), nums.end()) - nums.begin();

        int del_front = max(min_idx + 1, max_idx + 1);
        int del_back = max(n - min_idx, n - max_idx);

        int both_end =
            min(min_idx + 1, max_idx + 1) + min(n - min_idx, n - max_idx);

        return min({del_front, del_back, both_end});
    }
};