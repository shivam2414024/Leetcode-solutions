class Solution {
public:
    vector<int> leftRotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());

        return nums;
    }
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid,
                                    vector<int>& rowShift,
                                    vector<int>& colShift) {
        for (int i = 0; i < n; i++) {
            grid[i] = leftRotate(grid[i], rowShift[i]);
        }
        for (int j = 0; j < n; j++) {
            vector<int> arr(n);
            for (int i = 0; i < n; i++) {
                arr[i] = grid[i][j];
            }
            arr = leftRotate(arr, colShift[j]);
            for (int i = 0; i < n; i++) {
                grid[i][j] = arr[i];
            }
        }
        return grid;
    }
};