class Solution {
public:
    long long solve(string& str, string& inputSuffix, int limit) {
        if (str.size() < inputSuffix.size())
            return 0;
        long long count = 0;
        string trailString = str.substr(str.size() - inputSuffix.size());
        int remainL = str.size() - inputSuffix.size();
        for (int i = 0; i < remainL; i++) { // O(n)
            int digit = str[i] - '0';
            if (digit <= limit) {
                count += digit * pow(limit + 1, remainL - i - 1); // O(log)
            } else {
                count += pow(limit + 1, remainL - i);
                return count;
            }
        }
        if (trailString >= inputSuffix) {
            count++;
        }
        return count;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s) {
        string startStr = to_string(start - 1);
        string finishStr = to_string(finish);
        return solve(finishStr, s, limit) - solve(startStr, s, limit);
    }
};