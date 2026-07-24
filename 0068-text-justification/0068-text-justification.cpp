class Solution {
public:
    string findLine(int i, int j, int each_gap, int extra_gap,
                    vector<string>& words, int maxWidth) {
        string line = "";
        for (int k = i; k < j; k++) {
            line += words[k];

            if (k == j - 1)
                continue;

            for (int l = 1; l <= each_gap; l++) {
                line += " ";
            }

            if (extra_gap > 0) {
                line += " ";
                extra_gap--;
            }
        }
        while (line.size() < maxWidth) {
            line += " ";
        }

        return line;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;
        int i = 0;
        while (i < n) {
            int lettersCount = words[i].size();
            int gap = 0;
            int j = i + 1;
            while (j < n &&
                   words[j].size() + 1 + lettersCount + gap <= maxWidth) {
                lettersCount += words[j].size();
                gap++;
                j++;
            }
            int total_gap = maxWidth - lettersCount;
            int each_gap = gap == 0 ? 0 : total_gap / gap;
            int extra_gap = gap == 0 ? 0 : total_gap % gap;

            if (j == n) {
                each_gap = 1;
                extra_gap = 0;
            }

            ans.push_back(findLine(i, j, each_gap, extra_gap, words, maxWidth));

            i = j;
        }
        return ans;
    }
};