class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int even_count = 0;
        int odd_count = 0;
        int mini_even = INT_MAX;
        int mini_odd = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 0) {
                even_count++;
                mini_even = min(mini_even, nums1[i]);
            } else {
                odd_count++;
                mini_odd = min(mini_odd, nums1[i]);
            }
        }
        if (even_count == n || odd_count == n)
            return true;
        if (mini_even > mini_odd)
            return true;
        return false;
    }
};