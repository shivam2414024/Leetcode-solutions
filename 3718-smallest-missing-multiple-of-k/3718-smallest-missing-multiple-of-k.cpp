class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        int ans = 0;
        for (int i = 1; i <= 100; i++) {
            if (st.find(k * i) == st.end()) {
                ans = k * i;
                break;
            }
        }
        return ans == 0 ? k * 101 : ans;
    }
};