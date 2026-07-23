class Solution {
public:
    int numberOfChild(int n, int k) {
        int i = 1;
        bool forward = true;
        while (k > 0) {
            if (forward) {
                i++;
                k--;
            } else {
                i--;
                k--;
            }
            if (i == n) {
                forward = !forward;
            }
            if(i == 1){
                forward = !forward;
            }
        }
        return i-1;
    }
};