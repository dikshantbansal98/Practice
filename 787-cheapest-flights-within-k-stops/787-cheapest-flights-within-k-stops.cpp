class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        k++;
        vector<vector<int>>dp(n, vector<int>(k+1,1e9));
        for(int i = 0; i <= k; ++i) {
            dp[src][i] = 0;
        }
        vector<pair<int,int>>graph[n];
        for(auto flight: flights) {
            graph[flight[0]].push_back({flight[1],flight[2]});
        }
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>pq;
        pq.push({0,src,k});
        while(!pq.empty()) {
            auto [distance, src, k] = pq.top(); pq.pop();
            if(dst == src) {
                return distance;
            }
            for(auto [to,weight]: graph[src]) {
                if(k >= 1 && dp[to][k-1]>distance+weight) {
                    dp[to][k-1] = distance+weight;
                    pq.push({dp[to][k-1], to, k-1});
                }
            }
        }
        return -1;
    }
};
