class Solution {
public:
    vector<int>parent;
    int maximumInvitations(vector<vector<int>>& grid) {
        parent.resize(grid[0].size(), -1);
        int invitations = 0;
        for(int i = 0; i < grid.size(); ++i) {
            vector<bool>visited(grid[0].size());
            if(match(i, visited, grid)) {
                invitations++;
            }
        }
        return invitations;
    }
    
    bool match(int start, vector<bool>&visited, vector<vector<int>>& grid) {
        
        for(int to = 0; to < grid[start].size(); ++to) {
            if(!visited[to] && grid[start][to]) {
                visited[to] = true;
                if(parent[to]==-1 || match(parent[to], visited, grid)) {
                    parent[to] = start;
                    return true;
                }
            }
        }
        return false;
    }
};