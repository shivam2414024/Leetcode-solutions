class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;
        for (auto& it : reservedSeats) {
            int row = it[0];
            int seat = it[1];
            mp[row].insert(seat);
        }
        int groups = (n - mp.size()) * 2;
        for (auto& [row, reservedSeat] : mp) {
            auto isAvailable = [&](int seat) {
                return reservedSeat.find(seat) == reservedSeat.end();
            };
            bool GroupA = isAvailable(2) && isAvailable(3) && isAvailable(4) &&
                          isAvailable(5);
            bool GroupB = isAvailable(4) && isAvailable(5) && isAvailable(6) &&
                          isAvailable(7);
            bool GroupC = isAvailable(6) && isAvailable(7) && isAvailable(8) &&
                          isAvailable(9);

            if (GroupA && GroupC)
                groups += 2;
            else if (GroupA || GroupB || GroupC)
                groups++;
        }
        return groups;
    }
};