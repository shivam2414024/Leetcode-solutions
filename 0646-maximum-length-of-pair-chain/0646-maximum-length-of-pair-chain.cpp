class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        int len = 0;
        int prev = INT_MIN;
        for (auto& it : pairs) {
            if (it[0] > prev) {
                len++;
                prev = it[1];
            }
        }
        return len;
    }
};