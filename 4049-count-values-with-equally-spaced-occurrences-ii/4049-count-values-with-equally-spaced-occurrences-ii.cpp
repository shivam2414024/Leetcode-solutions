class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int count = 0;
        for (auto& [it, vec] : mp) {
            if(vec.size() >= 3){
                int x = vec[1]-vec[0];
                int flag= true;
                for(int i=2; i<vec.size(); i++){
                    if(vec[i]-vec[i-1] != x){
                        flag = false;
                        break;
                    }
                }
                if(flag)
                count++;
            }
        }
        return count;
    }
};