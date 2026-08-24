class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        map<int, int> mp;
        for (auto& it : trips) {
            mp[it[1]] += it[0];
            mp[it[2]] -= it[0];
        }
        int cumSum = 0;
        for (auto& it : mp) {
            cumSum += it.second;
            if (cumSum > capacity)
                return false;
        }
        return true;
    }
};