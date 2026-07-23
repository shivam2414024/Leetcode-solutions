class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        priority_queue<int> maxHeap;
        for (int i = 0; i < n; i++) {
            maxHeap.push(gifts[i]);
        }
        while (k > 0) {
            int x = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(sqrt(x));
            k--;
        }
        long long ans = 0;
        while(!maxHeap.empty()){
            ans += maxHeap.top();
            maxHeap.pop();
        }
        return ans;
    }
};