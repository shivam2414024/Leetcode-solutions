class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<tuple<int, int, int>>> adj;
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int start = it[2];
            int end = it[3];
            adj[u].push_back({v, start, end});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> dist(n, INT_MAX);
        pq.push({0, 0});
        dist[0] = 0;
        while (!pq.empty()) {
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();
            if (time > dist[node])
                continue;
            if (node == n - 1)
                return time;
            for (auto& [adjNode, sTime, eTime] : adj[node]) {
                int nTime;
                if (time >= sTime && time <= eTime) {
                    nTime = time + 1;
                } else if (time < sTime) {
                    nTime = sTime + 1;
                } else {
                    continue;
                }
                if (nTime < dist[adjNode]) {
                    pq.push({nTime, adjNode});
                    dist[adjNode] = nTime;
                }
            }
        }
        return -1;
    }
};