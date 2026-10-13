class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            pq.push(abs(nums[i]));
        }
        int k = n / 2;
        if (n % 2 != 0)
            k++;
        long long ans = 0;
        while (k--) {
            int num = pq.top();
            pq.pop();
            ans += (num * num);
        }
        while (!pq.empty()) {
            int num = pq.top();
            pq.pop();
            ans -= (num * num);
        }
        return ans;
    }
};