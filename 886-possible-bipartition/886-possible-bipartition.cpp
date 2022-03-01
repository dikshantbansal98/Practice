class Solution {
public:
    vector<vector<int>>graph;
    vector<int>values;
    bool is = true;
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        graph.resize(n+1);
        for(auto &dislike: dislikes) {
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }
        values = vector<int>(n+1,-1);
        for(int i = 1; i <= n; ++i) {
            if(values[i] == -1) {
                isBipartite(i,0);
            }
        }
        return is;
    }
    
    void isBipartite(int start, int value) {
        values[start] = value;
        for(auto &to: graph[start]) {
            if(values[to]==-1) {
                isBipartite(to, 1-value);
            }
            else {
                is &= (values[start] != values[to]);
            }
        }
    }
};