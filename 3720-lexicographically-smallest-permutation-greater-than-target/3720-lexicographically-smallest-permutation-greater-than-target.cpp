class Solution {
public:
    bool solve(string& curr, string& target, vector<int>& count, int idx,
               bool greater, string& result) {

        if (idx == target.size()) {
            if (greater) {
                result = curr;
                return true;
            }
            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {

            if (count[ch - 'a'] == 0)
                continue;

            if (!greater && ch < target[idx])
                continue;

            curr.push_back(ch);
            count[ch - 'a']--;

            bool isGreater = greater || ch > target[idx];

            if (solve(curr, target, count, idx + 1, isGreater, result))
                return true;

            curr.pop_back();
            count[ch - 'a']++;
        }

        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);

        for (auto& ch : s) {
            count[ch - 'a']++;
        }

        string curr;

        string result = "";

        solve(curr, target, count, 0, false, result);

        return result;
    }
};