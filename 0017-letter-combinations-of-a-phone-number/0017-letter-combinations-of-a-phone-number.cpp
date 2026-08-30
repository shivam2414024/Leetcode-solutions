class Solution {
public:
    void solve(int n, string& digits, unordered_map<int, string>& mp, string& s,
               vector<string>& ans, int idx) {
        if (idx == n) {
            ans.push_back(s);
            return;
        }

        for (auto& it : mp[digits[idx] - '0']) {
            s.push_back(it);
            solve(n, digits, mp, s, ans, idx + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        unordered_map<int, string> mp = {{2, "abc"}, {3, "def"}, {4, "ghi"},
                                         {5, "jkl"}, {6, "mno"}, {7, "pqrs"},
                                         {8, "tuv"}, {9, "wxyz"}};

        vector<string> ans;
        string s;
        solve(n, digits, mp, s, ans, 0);
        return ans;
    }
};