class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n), right(n);
        left[0] = 1;
        right[n - 1] = 1;
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                count++;
                left[i] = count;
            } else {
                count = 1;
                left[i] = count;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                count++;
                right[i] = count;
            } else {
                count = 1;
                right[i] = count;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += max(left[i], right[i]);
        }
        return ans;
    }
};