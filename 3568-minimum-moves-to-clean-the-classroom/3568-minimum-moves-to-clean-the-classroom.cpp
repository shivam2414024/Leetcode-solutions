class Solution {
public:
    using VB = vector<bool>;
    using VVB = vector<VB>;
    using VVVB = vector<VVB>;
    using VVVVB = vector<VVVB>;

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    struct State {
        int row;
        int col;
        int energyLeft;
        int collectedMask;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int maxEnergy = energy;

        int litterBit[20][20];
        int litterCount = 0;
        int StartR = 0;
        int StartC = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                litterBit[i][j] = -1;
                if (classroom[i][j] == 'S') {
                    StartR = i;
                    StartC = j;
                } else if (classroom[i][j] == 'L') {
                    litterBit[i][j] = litterCount; // 0th position
                    litterCount++;
                }
            }
        }

        int allCollected = (1 << litterCount) - 1;
        if (litterCount == 0)
            return 0;

        VVVVB visited(m,
                      VVVB(n, VVB(maxEnergy + 1, VB(1 << litterCount, false))));

        queue<State> q;
        q.push({StartR, StartC, maxEnergy, 0});
        visited[StartR][StartC][maxEnergy][0] = true;

        int moves = 0;

        while (!q.empty()) {
            int currSize = q.size();

            while (currSize--) {
                State curr = q.front();
                q.pop();

                if (curr.collectedMask == allCollected)
                    return moves;

                if (curr.energyLeft == 0)
                    continue;

                for (auto& dir : directions) {
                    int nextRow = curr.row + dir[0];
                    int nextCol = curr.col + dir[1];

                    if (nextRow >= m || nextRow < 0 || nextCol >= n ||
                        nextCol < 0)
                        continue;

                    char cell = classroom[nextRow][nextCol];
                    if (cell == 'X')
                        continue;

                    int nextEnergy = curr.energyLeft - 1;
                    int nextcollectedMask = curr.collectedMask;

                    if (cell == 'R')
                        nextEnergy = maxEnergy;

                    else if (cell == 'L')
                        nextcollectedMask |= (1 << litterBit[nextRow][nextCol]);

                    if (!visited[nextRow][nextCol][nextEnergy]
                                [nextcollectedMask]) {
                        visited[nextRow][nextCol][nextEnergy]
                               [nextcollectedMask] = true;
                        q.push(
                            {nextRow, nextCol, nextEnergy, nextcollectedMask});
                    }
                }
            }

            moves++;
        }
        return -1;
    }
    // TC : total states that will be visit : m*n*maxEnergy*2^10
    // SC : O(m*n*maxEnergy*2^10)
};