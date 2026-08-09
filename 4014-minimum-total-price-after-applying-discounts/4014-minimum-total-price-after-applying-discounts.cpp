class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        double ans = 0;
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());
        int i = 0;
        for (; i < min(discounts.size(), prices.size()); i++) {
            ans += (((double)prices[i] * (100 - discounts[i])) / 100);
        }
        while (i < prices.size()) {
            ans += prices[i];
            i++;
        }
        return ans;
    }
};