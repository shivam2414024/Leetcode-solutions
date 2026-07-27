class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long req = llabs((long long)goal - sum);
        return (req + limit - 1) / limit;
    }
};