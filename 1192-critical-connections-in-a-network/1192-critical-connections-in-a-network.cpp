class Solution {
    vector<vector<int>> bridges;
    int numberOfNodes;
    vector<vector<int>> adj, result;
    vector<bool>visited;
    vector<int>in, low;
    int time;

public:
    void createGraph(vector<vector<int>>& connections) {
        adj.resize(numberOfNodes);
        for(auto connection: connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        numberOfNodes = n;
        createGraph(connections);
        visited.resize(n);
        in.resize(n);
        low.resize(n);
        time = 0;
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                dfs(i, -1);
            }
        }
        return result;
    }
    
    void addBridge(int start, int destination) {
        result.push_back({start, destination});
    }
    
    void dfs(int source, int parent = -1) {
        visited[source] = true;
        in[source] = low[source] = ++time;
        for(int &to: adj[source]) {
            if(parent == to) {
                continue;
            }
            if(visited[to]) {
                low[source] = min(low[source], low[to]);
            }
            else {
                dfs(to, source);
                low[source] = min({low[source], low[to]});
            }
            if(low[to]>in[source]) {
                addBridge(source, to);
            }
        }
    }
};