class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        if (n == 1)
            return 1;

        int count = 0;
        int mini = speed[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (speed[i] <= mini &&
                abs(position[i] - position[i + 1]) > distance) {
                count++;
                mini = speed[i];
            }
        }
        count++;
        return count;
    }
};