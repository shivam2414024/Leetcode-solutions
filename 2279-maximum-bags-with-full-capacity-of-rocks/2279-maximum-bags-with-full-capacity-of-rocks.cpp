class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks,
                    int additionalRocks) {
        int n = capacity.size();
        vector<long long> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = capacity[i] - rocks[i];
        }
        sort(diff.begin(), diff.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (additionalRocks >= diff[i]) {
                ans++;
                additionalRocks -= diff[i];
            } else
                break;
        }
        return ans;
    }
};