class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto& it : mp) {
            vector<int> vec = it.second;
            bool flag = true;
            for (int i = 0; i < vec.size() - 1; i++) {
                if (vec[i] + 1 != vec[i + 1]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans++;
        }

        return ans;
    }
};