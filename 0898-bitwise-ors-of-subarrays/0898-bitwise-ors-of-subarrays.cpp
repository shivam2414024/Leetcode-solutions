class Solution {
public:
    // TC: O(n*32)  SC: O(32)
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> curr;
        unordered_set<int> prev;

        for (int i = 0; i < arr.size(); i++) {

            for (auto& it : prev) {
                curr.insert(it | arr[i]);
                ans.insert(it | arr[i]);
            }

            curr.insert(arr[i]);
            ans.insert(arr[i]);

            prev = curr;
            curr.clear();
        }

        return ans.size();
    }
};