class Solution {
public:
    bool solve(vector<double>& cards) {
        if (cards.size() == 1) {
            if (abs(cards[0] - 24) <= 1e-6)
                return true;
        }
        int n = cards.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                vector<double> vec;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j)
                        vec.push_back(cards[k]);
                }
                double a = cards[i];
                double b = cards[j];
                vector<double> possible = {a + b, a - b, b - a, a * b};
                if (a != 0)
                    possible.push_back(b / a);
                if (b != 0)
                    possible.push_back(a / b);
                for (auto& num : possible) {
                    vec.push_back(num);
                    if (solve(vec))
                        return true;
                    vec.pop_back();
                }
            }
        }

        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> vec;
        for (auto& num : cards)
            vec.push_back(1.0 * num);
        return solve(vec);
    }
};