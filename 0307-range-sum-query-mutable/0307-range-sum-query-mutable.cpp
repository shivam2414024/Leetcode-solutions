class NumArray {
public:
    int n;
    vector<int> segmentTree; // SC: O(N)

    void buildSegmentTree(int i, int l, int r, vector<int>& nums) { // O(N)
        if (l == r) {
            segmentTree[i] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, nums);
        buildSegmentTree(2 * i + 2, mid + 1, r, nums);

        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4 * n);
        buildSegmentTree(0, 0, n - 1, nums);
    }

    void updateSegmentTree(int index, int val, int i, int l,
                           int r) { // O(log N)
        if (l == r) {
            segmentTree[i] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (index <= mid) {
            updateSegmentTree(index, val, 2 * i + 1, l, mid);
        } else {
            updateSegmentTree(index, val, 2 * i + 2, mid + 1, r);
        }

        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }

    void update(int index, int val) {
        updateSegmentTree(index, val, 0, 0, n - 1);
    }

    int querySegmentTree(int s, int e, int i, int l, int r) { // O(log N)
        if (r < s || l > e) {
            return 0;
        }
        if (l >= s && r <= e) {
            return segmentTree[i];
        }
        int mid = l + (r - l) / 2;
        return querySegmentTree(s, e, 2 * i + 1, l, mid) +
               querySegmentTree(s, e, 2 * i + 2, mid + 1, r);
    }

    int sumRange(int left, int right) {
        return querySegmentTree(left, right, 0, 0, n - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */