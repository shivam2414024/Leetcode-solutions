class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftKnowSum = 0;
        int rightKnowSum = 0;
        int leftQmarkCount = 0;
        int rightQmarkCount = 0;
        for (int i = 0; i < n; i++) {
            if (num[i] == '?') {
                if (i < n / 2) {
                    leftQmarkCount++;
                } else {
                    rightQmarkCount++;
                }
            } else {
                if (i < n / 2) {
                    leftKnowSum += num[i] - '0';
                } else {
                    rightKnowSum += num[i] - '0';
                }
            }
        }
        int totalQmark = leftQmarkCount + rightQmarkCount;
        if (totalQmark % 2 == 1)
            return true;

        int LEFT = 2 * leftKnowSum + (9 * leftQmarkCount);
        int RIGHT = 2 * rightKnowSum + (9 * rightQmarkCount);

        return (LEFT != RIGHT) ? true : false;
    }
};