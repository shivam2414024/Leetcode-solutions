class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int ans = 0;
        stack<char> st;
        int i = 0;
        while (i < n) {
            if (s[i] == '(') {
                st.push(s[i]);
                i++;
            } else {
                if (!st.empty() && s[i] == ')' && i == n - 1) {
                    ans += 1;
                    st.pop();
                    i++;
                } else if (!st.empty() && s[i] == ')' && s[i + 1] == ')') {
                    st.pop();
                    i += 2;
                } else if (!st.empty() && s[i] == ')' && s[i + 1] != ')') {
                    ans += 1;
                    st.pop();
                    i++;
                } else if (st.empty() && s[i] == ')' && s[i + 1] == ')') {
                    ans += 1;
                    i += 2;
                } else if (st.empty() && s[i] == ')' && i == n - 1) {
                    ans += 2;
                    i++;
                } else if(st.empty() && s[i] == ')' && s[i+1] != ')'){
                    ans += 2;
                    i++;
                }
            }
        }
        if (!st.empty())
            ans += (st.size() * 2);
        return ans;
    }
};