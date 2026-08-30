class Solution {
public:
    void solve(int n, vector<int>& cookies, vector<int>& children, int k,
               int idx, int& result) {
        if (idx == n) {
            int maxi = *max_element(children.begin(), children.end());
            result = min(result, maxi);
            return;
        }

        for (int i = 0; i < k; i++) {
            children[i] += cookies[idx];

            solve(n, cookies, children, k, idx + 1, result);

            children[i] -= cookies[idx];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> children(k);
        int result = INT_MAX;
        solve(n, cookies, children, k, 0, result);
        return result;
    }
};