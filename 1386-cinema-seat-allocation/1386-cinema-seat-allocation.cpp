class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;
        for (auto& it : reservedSeats) { // O(10^4)
            int row = it[0];
            int seat = it[1];
            mp[row] = mp[row] | (1 << seat);
        }
        int groups = (n - mp.size()) * 2;
        int maskA = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int maskB = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int maskC = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);
        for (auto& [row, reservedSeatMask] : mp) { // O(10^4)

            bool GroupA = (reservedSeatMask & maskA) == 0;
            bool GroupB = (reservedSeatMask & maskB) == 0;
            bool GroupC = (reservedSeatMask & maskC) == 0;

            if (GroupA && GroupC)
                groups += 2;
            else if (GroupA || GroupB || GroupC)
                groups++;
        }
        return groups;
    }
};