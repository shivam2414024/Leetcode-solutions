class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int, int>> arr;
        for (auto& it : logs) {
            arr.push_back({it[0], 1});
            arr.push_back({it[1], -1});
        }
        sort(arr.begin(), arr.end());
        int maxPop = 0;
        int curPop = 0;
        int minYear = INT_MAX;
        for (auto& it : arr) {
            curPop += it.second;
            if (curPop > maxPop) {
                minYear = it.first;
                maxPop = curPop;
            }
        }
        return minYear;
    }
};