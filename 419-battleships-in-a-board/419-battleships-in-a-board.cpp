const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};

class Solution {
public:
    vector<vector<char>>grid;
    vector<vector<bool>>visited;
    int rows, cols, maxX, maxY, minX, minY;
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        grid = board;
        rows = grid.size();
        if(rows == 0) {
            return 0;
        }
        cols = grid[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols));
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(grid[i][j]=='.') {
                    continue;
                }
                maxX = maxY = -1e9;
                minX = minY = 1e9;
                dfs(i,j);
                if(maxX == minX || maxY == minY) {
                    count++;
                }
            }
        }
        return count;
    }
    
    void dfs(int x, int y) {
        if(x < 0 || y < 0 || x >= rows || y >= cols || visited[x][y] || grid[x][y]=='.') {
            return;
        }
        grid[x][y] = '.';
        minX = min(minX,x);
        minY = min(minY,y);
        maxX = max(maxX,x);
        maxY = max(maxY,y);
        for(int i = 0; i < 4; ++i) {
            dfs(x+dx[i],y+dy[i]);
        }
    }
};