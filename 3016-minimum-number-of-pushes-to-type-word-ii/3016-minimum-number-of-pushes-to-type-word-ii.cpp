class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> a(26, 0);
        for (int i = 0; i < n; i++) {
            a[word[i] - 'a']++;
        }
        sort(a.rbegin(), a.rend());
        int count = 1;
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (i != 0 && i % 8 == 0) {
                count++;
            }
            ans += (count * a[i]);
        }
        return ans;
    }
};