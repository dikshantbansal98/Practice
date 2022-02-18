const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    vector<vector<int>>matrix;
    vector<vector<bool>>visited;
    int rows, cols;
    int shortestBridge(vector<vector<int>>& grid) {
        int value = 1;
        matrix = grid;
        rows = matrix.size();
        cols = grid.size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols));
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(matrix[i][j] && !visited[i][j]) {
                    dfs(i, j, value++);
                }
            }
        }
        return getShortestBridge();
    }
    
    int getShortestBridge() {
        visited = vector<vector<bool>>(rows, vector<bool>(cols));
        queue<tuple<int,int,int>>q;
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(matrix[i][j] == 1) {
                    q.push({i,j,0});
                    visited[i][j] = true;
                }
            }
        }
        while(!q.empty()) {
            auto [x,y,steps] = q.front();
            if(matrix[x][y] == 2) {
                return steps-1;
            }
            q.pop();
            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx>=0 && nx<rows && ny<cols && ny>=0 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx,ny,steps+1});
                }
            }
        }
        return 0;
    }
    
    void dfs(int x, int y, int value) {
        if(x<0 || y<0 || x>=rows || y>=cols || visited[x][y] || matrix[x][y]==0) {
            return;
        }
        visited[x][y] = true;
        matrix[x][y] = value;
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            dfs(nx,ny,value);
        }
    }
};

// 11111
// 10001
// 10101
// 10001
// 11111