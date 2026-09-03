class Solution {
public:
    void solve(int n, string curr, vector<string>& ans) {
        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!curr.empty() && curr.back() == ch)
                continue;
            curr.push_back(ch);
            solve(n, curr, ans);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<string> ans;
        string curr = "";
        solve(n, curr, ans);

        if (k > ans.size())
            return "";
        return ans[k - 1];
    }
};