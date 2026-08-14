class Solution {
public:
    void buildSegmentTree(int i, int l, int r, int segmentTree[],
                          vector<int>& heights) {
        if (l == r) {
            segmentTree[i] = l;
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, segmentTree, heights);
        buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, heights);
        segmentTree[i] =
            (heights[segmentTree[2 * i + 1]] >= heights[segmentTree[2 * i + 2]]
                 ? segmentTree[2 * i + 1]
                 : segmentTree[2 * i + 2]);
    }

    int* constructST(vector<int>& heights, int n) {
        int* segmentTree = new int[4 * n];
        buildSegmentTree(0, 0, n - 1, segmentTree, heights);
        return segmentTree;
    }

    int querySegmentTree(int s, int e, int i, int l, int r, int segmentTree[],
                         vector<int>& heights) {
        if (l > e || r < s)
            return -1;
        if (l >= s && r <= e) {
            return segmentTree[i];
        }
        int mid = l + (r - l) / 2;

        int leftIndex =
            querySegmentTree(s, e, 2 * i + 1, l, mid, segmentTree, heights);
        int rightIndex =
            querySegmentTree(s, e, 2 * i + 2, mid + 1, r, segmentTree, heights);

        if (leftIndex == -1)
            return rightIndex;
        if (rightIndex == -1)
            return leftIndex;

        return (heights[leftIndex] >= heights[rightIndex] ? leftIndex
                                                          : rightIndex);
    }

    int RMIQ(int segmentTree[], vector<int>& heights, int n, int s, int e) {
        return querySegmentTree(s, e, 0, 0, n - 1, segmentTree, heights);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        int n = heights.size();
        int* segmentTree = constructST(heights, n);
        vector<int> ans;
        for (auto& query : queries) {
            int min_idx = min(query[0], query[1]);
            int max_idx = max(query[0], query[1]);

            if (min_idx == max_idx) {
                ans.push_back(max_idx);
                continue;
            } else if (heights[max_idx] > heights[min_idx]) {
                ans.push_back(max_idx);
                continue;
            }
            int l = max_idx + 1, r = n - 1;
            int res = INT_MAX;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                int idx = RMIQ(segmentTree, heights, n, l, mid);
                if (heights[idx] > max(heights[max_idx], heights[min_idx])) {
                    res = min(res, idx);
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (res == INT_MAX)
                ans.push_back(-1);
            else
                ans.push_back(res);
        }
        return ans;
    }
};