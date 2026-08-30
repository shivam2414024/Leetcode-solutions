class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();
        vector<string> res(n);

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            string s = "";
            int power = 33554432;
            while (x >= power) {
                s += 'z';
                x -= power;
            }

            for (int k = 24; k >= 0; k--) {
                power /= 2;
                if (x >= power) {
                    s += ('a' + k);
                    x -= power;
                }
            }

            res[i] = s;
        }

        return res;
    }
};