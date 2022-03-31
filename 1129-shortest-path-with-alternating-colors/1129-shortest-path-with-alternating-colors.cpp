class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<vector<int>>>adj;
        adj.resize(n+1);
        map<vector<int>,bool>vis;
        for(auto edge:red_edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back({v,0});
        }
        for(auto edge: blue_edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back({v,1});
        }
        queue<tuple<int,int,int>>q;
        vector<vector<int>>distance(n,vector<int>(2,1e6));
        distance[0][0] = distance[0][1] = 0;
        q.push({0,-1,0});
        while(!q.empty()) {
            auto [u,type,distance_covered] = q.front(); q.pop();
            for(auto edge:adj[u]) {
                int destination = edge[0], color = edge[1];
                if(type!=color && distance[destination][color]>distance_covered+1) {
                    q.push({destination,color,distance_covered+1});
                    distance[destination][color] = distance_covered+1;
                }
            }
            
        }
        vector<int>result;
        for(int i = 0; i < n; ++i) {
            result.push_back(min(distance[i][0],distance[i][1]));
        }
        for(auto &i:result)
            if(i==1e6)
                i = -1;
        return result;
        
    }
};