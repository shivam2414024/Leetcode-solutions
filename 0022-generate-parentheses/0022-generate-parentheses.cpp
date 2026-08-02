class Solution {
public:
    // TC: O(2^2n)  SC: O(2n)
    bool isValid(string& s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                count++;
            else
                count--;
            if (count < 0)
                return false;
        }
        return count == 0;
    }
    void solve(string& s, int n, vector<string>& ans) {
        if (s.size() == 2 * n) {
            if (isValid(s)) {
                ans.push_back(s);
            }
            return;
        }
        s.push_back('(');
        solve(s, n, ans);
        s.pop_back();
        s.push_back(')');
        solve(s, n, ans);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        solve(s, n, ans);
        return ans;
    }
};