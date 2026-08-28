class Solution {
public:
    bool solve(int halfLen, char midChar, string& curr, string& target,
               vector<int>& count, int idx, bool greater, string& result) {

        if (curr.size() == halfLen) {
            string leftHalf = curr;
            string rightHalf = curr;

            reverse(rightHalf.begin(), rightHalf.end());

            if (midChar != '$') {
                leftHalf += midChar;
            }

            leftHalf += rightHalf;

            if (leftHalf > target) {
                result = leftHalf;
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

            if (solve(halfLen, midChar, curr, target, count, idx + 1, isGreater,
                      result))
                return true;

            curr.pop_back();
            count[ch - 'a']++;
        }

        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> count(26, 0);

        for (auto& ch : s)
            count[ch - 'a']++;

        int odd_count_freq = 0;
        char midChar = '$';
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                odd_count_freq++;
                midChar = i + 'a';
            }
            if (odd_count_freq > 1)
                return "";
        }

        for (int i = 0; i < 26; i++) {
            count[i] /= 2;
        }

        int halfLen = n / 2;

        string result = "";

        string curr;

        solve(halfLen, midChar, curr, target, count, 0, false, result);

        return result;
    }
};