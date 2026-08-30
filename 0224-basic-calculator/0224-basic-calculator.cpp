class Solution {
public:
    int calculate(string s) {
        int n = s.size();

        long long result = 0;
        long long number = 0;
        int sign = 1;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                number = (number * 10) + (s[i] - '0');
            } else if (s[i] == '+') {
                result += (sign * number);
                number = 0;
                sign = 1;
            } else if (s[i] == '-') {
                result += (sign * number);
                number = 0;
                sign = -1;
            } else if (s[i] == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if (s[i] == ')') {
                result += (sign * number);
                number = 0;

                int stack_sign = st.top();
                st.pop();
                int stack_res = st.top();
                st.pop();

                result = stack_sign * result;
                result += stack_res;
            }
        }

        result += (sign * number);
        return result;
    }
};