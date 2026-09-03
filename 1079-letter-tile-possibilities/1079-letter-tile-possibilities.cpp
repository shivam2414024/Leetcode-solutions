class Solution {
public:
    void solve(int n, vector<int>& freq, string curr, int& count) {
        count++;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0)
                continue;

            freq[i]--;
            curr.push_back(i + 'A');

            solve(n, freq, curr, count);

            freq[i]++;
            curr.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<int> freq(26, 0);
        for (auto& ch : tiles)
            freq[ch - 'A']++;
        int count = 0;
        string curr = "";
        solve(n, freq, curr, count);
        return count - 1;
    }
};