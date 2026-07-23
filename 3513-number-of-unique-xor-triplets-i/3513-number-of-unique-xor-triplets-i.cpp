class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || n == 2) return n;
        int ans = 0;
        for(int i=1; i<n; i++){
            if(pow(2, i) > n){
                ans = pow(2,i);
                break;
            }
        }
        return ans;
    }
};