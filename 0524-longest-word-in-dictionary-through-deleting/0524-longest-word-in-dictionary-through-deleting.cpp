class Solution {
public:
    string compare(string a, string b) {
        int l = a.size();
        for (int i = 0; i < l; i++) {
            if (b[i] < a[i])
                return b;
            else if (a[i] < b[i])
                return a;
        }
        return a;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        int n = s.size();
        int m = dictionary.size();
        string ans = "";
        for (int i = 0; i < m; i++) {
            string st = dictionary[i];
            int l = st.size();
            int k = 0;
            for (int j = 0; j < n; j++) {
                if (k < n && st[k] == s[j]) {
                    k++;
                }
                if (k == l) {
                    if (ans == "") {
                        ans = st;
                    } else {
                        if (ans.size() < st.size()) {
                            ans = st;
                        } else if (ans.size() == st.size()) {
                            ans = compare(ans, st);
                        }
                    }
                    break;
                }
            }
        }
        return ans;
    }
};