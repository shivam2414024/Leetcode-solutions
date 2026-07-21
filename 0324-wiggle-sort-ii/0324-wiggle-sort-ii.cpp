class Solution {
public:
    // TC : O(NlogN)
    // SC : O(N)
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> arr(n);
        int i = 1, j = n - 1;
        while (i < n) {
            arr[i] = nums[j];
            i += 2;
            j--;
        }
        i = 0;
        while (j >= 0) {
            arr[i] = nums[j];
            i += 2;
            j--;
        }
        nums = arr;
    }
};