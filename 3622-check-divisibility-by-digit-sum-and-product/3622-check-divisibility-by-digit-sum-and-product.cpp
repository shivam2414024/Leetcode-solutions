class Solution {
public:
    bool checkDivisibility(int n) {
        int x = n;
        int digit_Sum = 0;
        int digit_Prod = 1;

        while (x != 0) {
            int digit = x % 10;
            digit_Sum += digit;
            digit_Prod *= digit;
            x /= 10;
        }
        int sum = digit_Sum + digit_Prod;
        return n % sum == 0;
    }
};