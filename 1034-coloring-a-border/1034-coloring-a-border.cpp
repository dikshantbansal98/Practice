const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    int rows, cols;
    set<pair<int,int>>vis;
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int x, int y, int color) {
        rows = grid.size();
        if(!rows || color == grid[x][y]) {
            return grid;
        }
        cols = grid[0].size();
        vis.insert({x,y});
        dfs(grid,x,y,color);
        return grid;
    }
    void dfs(vector<vector<int>>& grid, int x, int y, int &color)
    {
        bool flag = false;
        for(int i = 0; i < 4; ++i) {
            int nx = x+dx[i], ny = y+dy[i];
            if(nx<0 || ny<0 || nx>=rows || ny>=cols) {
                flag = true;
                continue;
            }
            if(vis.find({nx,ny})!=vis.end()) {
                continue;
            }
            if(grid[nx][ny] == grid[x][y]) {
                vis.insert({nx,ny});
                dfs(grid,nx,ny,color);
            }
            else {
                flag = true;
            }
        }
        if(flag) {
            grid[x][y] = color;
        }
    }
};