typedef pair<double,int> type;
class Solution {
public:
    vector<vector<pair<int,double>>>adj;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        if(start == end) {
            return 0;
        }
        adj.resize(n+1);
        for(int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double>distances(n+1,0);
        distances[start]=1;
        priority_queue<type>pq;
        pq.push({1,start});
        while(!pq.empty()) {
            auto [distance,start] = pq.top(); pq.pop();
            for(auto &[to,length]: adj[start]) {
                if(distances[to]<distances[start]*length) {
                    distances[to] = distances[start]*length;
                    pq.push({distances[to],to});
                }
            }
        }
        return distances[end];
    }
};