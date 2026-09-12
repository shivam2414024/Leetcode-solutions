class Solution {
public:
    struct Node {
        long long score = -1;
        vector<int> idxs;
    };

    int nextIndex(vector<vector<int>>& intervals, int n, int x) {
        int l = 0, r = n - 1;
        int ans = n;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (intervals[m][0] > x) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }

    Node solve(int n, vector<vector<int>>& intervals, vector<int>& nextIdx,
               int i, int k, vector<vector<Node>>& dp) {
        if (k == 0 || i >= n) {
            return Node();
        }

        if (dp[i][k].score != -1)
            return dp[i][k];

        Node skip = solve(n, intervals, nextIdx, i + 1, k, dp);

        int weight = intervals[i][2];
        int idx = intervals[i][3];
        int j = nextIdx[i];

        Node temp = solve(n, intervals, nextIdx, j, k - 1, dp);
        Node take;
        take.score = temp.score + weight;
        take.idxs = temp.idxs;
        take.idxs.push_back(idx);
        sort(take.idxs.begin(), take.idxs.end());

        Node result;
        if (skip.score > take.score) {
            result = skip;
        } else if (skip.score < take.score) {
            result = take;
        } else {
            result = (skip.idxs < take.idxs) ? skip : take;
        }

        return dp[i][k] = result;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i = 0; i < n; i++)
            intervals[i].push_back(i);

        vector<int> nextIdx(n);
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < n; i++) {
            int x = intervals[i][1];
            nextIdx[i] = nextIndex(intervals, n, x);
        }

        int k = 4;
        vector<vector<Node>> dp(n + 1, vector<Node>(k + 1));

        return solve(n, intervals, nextIdx, 0, k, dp).idxs;
    }
};