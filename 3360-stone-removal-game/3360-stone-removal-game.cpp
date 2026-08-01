class Solution {
public:
    bool canAliceWin(int n) {
        int alice = 1;
        int prev = 10;
        while (prev <= n) {
            n -= prev;
            alice = !alice;
            prev = prev - 1;
        }
        if (alice == 1)
            return false;
        return true;
    }
};