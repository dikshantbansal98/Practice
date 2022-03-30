const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    int rows, cols;
    vector<vector<int>>result;
    vector<vector<int>>grid;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        rows = matrix.size();
        if(rows==0)
            return result;
        cols = matrix[0].size();
        grid = matrix;
        set<pair<int,int>>pacificPoints = getPoints(true);
        set<pair<int,int>>atlanticPoints = getPoints(false);
        for(auto point: pacificPoints) {
            if(atlanticPoints.find(point)!=atlanticPoints.end()) {
                result.push_back({point.first,point.second});
            }
        }
        return result;
    }
    
    set<pair<int,int>>getPoints(bool isPacific)
    {
        set<pair<int,int>>ocean;
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));
        priority_queue<tuple<int,int,int>>pq;
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if((isPacific && (i==0||j==0)) || (!isPacific && (i == rows-1 || j == cols-1))) {
                    ocean.insert({i,j});
                    pq.push({grid[i][j],i,j});
                }
            }
        }
        while(!pq.empty())
        {
            auto [height, x, y] = pq.top(); pq.pop();
            for(int i = 0; i < 4; ++i)
            {
                int nx = x+dx[i], ny = y+dy[i];
                if(nx>=0 && ny>=0 && nx<rows && ny<cols && ocean.find({nx,ny}) == ocean.end() && grid[nx][ny]>=height)
                {
                    pq.push({grid[nx][ny],nx,ny});
                    ocean.insert({nx,ny});
                }
            }
        }
        return ocean;
        
    }
};