class Solution {
public:
    bool solve(string bottom, unordered_map<string, vector<char>>& mp,
               string curr, int idx, unordered_map<string, bool>& dp) {

        if (bottom.size() == 1)
            return true;
        if (idx == 0 && dp.find(bottom) != dp.end())
            return dp[bottom];
        if (idx == bottom.size() - 1) {
            string next = "";
            return dp[bottom] = solve(curr, mp, next, 0, dp);
        }

        string key = bottom.substr(idx, 2);
        if (mp.find(key) == mp.end())
            return false;
        for (auto& ch : mp[key]) {
            curr.push_back(ch);
            if (solve(bottom, mp, curr, idx + 1, dp))
                return true;
            curr.pop_back();
        }

        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;

        for (auto& s : allowed) {
            string key = s.substr(0, 2);
            mp[key].push_back(s[2]);
        }
        string curr = "";
        unordered_map<string, bool> dp;
        return solve(bottom, mp, curr, 0, dp);
    }
};