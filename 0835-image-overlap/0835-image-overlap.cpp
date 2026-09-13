class Solution {
public:
    int solve(int n, vector<vector<int>>& img1, vector<vector<int>>& img2,
              int rowOff, int colOff) {
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int i_ = i + rowOff;
                int j_ = j + colOff;

                if (i_ < 0 || i_ >= n || j_ < 0 || j_ >= n)
                    continue;

                if (img1[i_][j_] == 1 && img2[i][j] == 1)
                    count++;
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxOverlap = INT_MIN;

        for (int rowOff = -n + 1; rowOff < n; rowOff++) {
            for (int colOff = -n + 1; colOff < n; colOff++) {
                maxOverlap =
                    max(maxOverlap, solve(n, img1, img2, rowOff, colOff));
            }
        }

        return maxOverlap;
    }
};