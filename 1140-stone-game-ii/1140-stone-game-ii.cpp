class Solution {
public:
    int solveForAlice(vector<int>& piles, int person, int i, int M,
                      vector<vector<vector<int>>>& dp) {
        int n = piles.size();
        if (i >= n)
            return 0;
        if (dp[person][i][M] != -1)
            return dp[person][i][M];
        int result = (person == 1) ? -1 : INT_MAX;
        int stones = 0;
        for (int x = 1; x <= min(2 * M, n - i); x++) {
            stones += piles[i + x - 1];
            if (person) {
                result = max(result, stones + solveForAlice(piles, 0, i + x,
                                                            max(M, x), dp));
            } else {
                result =
                    min(result, solveForAlice(piles, 1, i + x, max(M, x), dp));
            }
        }
        return dp[person][i][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(
            2, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        return solveForAlice(piles, 1, 0, 1, dp);
    }
};