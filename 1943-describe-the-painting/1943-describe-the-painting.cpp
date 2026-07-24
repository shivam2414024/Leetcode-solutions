class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int n = segments.size();
        vector<vector<long long>> ans;
        map<int, long long> mp;
        for (int i = 0; i < n; i++) {
            mp[segments[i][0]] += segments[i][2];
            mp[segments[i][1]] -= segments[i][2];
        }

        auto it = mp.begin();
        long long sum = it->second;
        int start = it->first;
        it++;

        while (it != mp.end()) {
            if (sum > 0) {
                ans.push_back({start, it->first, sum});
            }
            start = it->first;
            sum += it->second;
            it++;
        }

        return ans;
    }
};