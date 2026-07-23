class Solution {
public:
    int passThePillow(int n, int time) {
        int i = 1;
        bool forward = true;
        while (time > 0) {
            if (forward) {
                i++;
                time--;
            } else {
                i--;
                time--;
            }
            if (i == n) {
                forward = !forward;
            }
            if(i == 1){
                forward = !forward;
            }
        }
        return i;
    }
};