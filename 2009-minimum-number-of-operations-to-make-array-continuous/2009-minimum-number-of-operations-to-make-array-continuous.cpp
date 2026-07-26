class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = INT_MAX;
        set<int> st(nums.begin(), nums.end());
        vector<int> arr(st.begin(), st.end());
        for (int i = 0; i < arr.size(); i++) {
            int l = arr[i];
            int r = l + n - 1;
            int j = upper_bound(arr.begin(), arr.end(), r) - arr.begin();
            int within_range = j - i;
            int out_of_range = n - within_range;
            operations = min(operations, out_of_range);
        }
        return operations;
    }
};