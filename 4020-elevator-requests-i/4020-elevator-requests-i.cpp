class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int m = requests.size();
        int time = 0;
        int prev = 0;
        for (int i = 0; i < m; i++) {
            prev = abs(requests[i] - prev);
            time += prev;
            prev = requests[i];
        }
        return time;
    }
};