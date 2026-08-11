class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        for (int i = 1; i < n; i++) {
            if ((nums[i - 1] + 1) == nums[i]) {
                sum += nums[i];
            } else {
                break;
            }
        }
        int ans = 0;
        int i = sum;
        while (true) {
            if (st.find(i) == st.end()) {
                ans = i;
                break;
            }
            i++;
        }
        return ans;
    }
};