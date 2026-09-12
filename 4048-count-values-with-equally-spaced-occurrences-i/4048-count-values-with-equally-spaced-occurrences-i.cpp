class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int count = 0;
        for (auto& [it, vec] : mp) {
            if (vec.size() == 3 && ((vec[1] - vec[0]) == (vec[2] - vec[1]))) {
                count++;
            }
        }
        return count;
    }
};