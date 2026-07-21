class Solution {
public:
    bool check(int k, vector<int>& inventory, int orders) {
        long long count = 0;
        for (int i = 0; i < inventory.size(); i++) {
            if (inventory[i] > k) {
                count += (inventory[i] - k);
            }
            if (inventory[i] >= k) {
                count++;
            }
            if (count >= orders) {
                return true;
            }
        }
        return count >= orders;
    }
    int maxProfit(vector<int>& inventory, int orders) {
        const int MOD = 1e9 + 7;
        int n = inventory.size();
        sort(inventory.rbegin(), inventory.rend());
        int low = 0;
        int high = inventory[0];
        int k = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, inventory, orders)) {
                k = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int balls = inventory[i];
            if (balls > k) {
                orders -= (balls - k);
                long long x =
                    (balls * 1LL * (balls + 1)) / 2 - (k * 1LL * (k + 1)) / 2;
                sum = (sum + x) % MOD;
            }
            if (orders == 0)
                break;
        }
        sum = (sum + (k * 1LL * orders)) % MOD;
        return sum;
    }
};