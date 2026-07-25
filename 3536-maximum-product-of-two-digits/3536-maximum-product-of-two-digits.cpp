class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr;
        while (n != 0) {
            int digit = n % 10;
            arr.push_back(digit);
            n = n / 10;
        }
        int maxi = INT_MIN;
        for (int i = 0; i < arr.size()-1; i++) {
            for (int j = i+1; j < arr.size(); j++) {
                maxi = max(maxi, arr[i] * arr[j]);
            }
        }
        return maxi;
    }
};