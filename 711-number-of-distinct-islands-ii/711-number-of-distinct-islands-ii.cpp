const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    set<map<int,int>>set;
    vector<vector<bool>>visited;
    int rows, cols;
    vector<vector<int>> matrix;
    int numDistinctIslands2(vector<vector<int>>& grid) {
        matrix = grid;
        rows = grid.size(), cols = grid[0].size();
        visited = vector<vector<bool>>(rows,vector<bool>(cols));
        bool isSingle = false;
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(grid[i][j] && !visited[i][j]) {
                    vector<pair<int,int>>points;
                    dfs(i,j,points);
                    if(points.size() == 1) {
                        isSingle = true;
                    }
                    else {
                        map<int,int>distances;
                        for(int i = 0; i < points.size(); ++i) {
                            for(int j = i+1; j < points.size(); ++j) {
                                int distance = (points[j].second-points[i].second)*(points[j].second-points[i].second) + 
                                    (points[j].first-points[i].first)*(points[j].first-points[i].first);
                                distances[distance]++;
                            }
                        }
                        set.insert(distances);
                    }
                }
            }
        }
        return set.size()+isSingle;
    }
    void dfs(int x, int y, vector<pair<int,int>>&points) {
        if(x < 0 || y < 0 || x >= rows || y >= cols || matrix[x][y]==0 || visited[x][y]) {
            return;
        }
        points.push_back({x,y});
        visited[x][y] = true;
        for(int i = 0; i < 4; ++i) {
            dfs(x+dx[i], y+dy[i], points);
        }
    }
};