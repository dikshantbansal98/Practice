const int dx[] = {-2,-2,-1,-1,1,1,2,2};
const int dy[] = {-1,1,-2,2,-2,2,-1,1};
class Solution {
public:
    int minKnightMoves(int endX, int endY) {
        queue<tuple<int,int,int>>q;
        q.push({0,0,0});
        unordered_set<int>visited;
        visited.insert(0);
        while(!q.empty()) {
            auto [x,y,steps] = q.front(); q.pop(); 
            if(endX == x && endY == y) {
                return steps;
            }
            for(int i = 0; i < 8; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                int value = abs(nx)+abs(ny);
                if(value > 300 || value < 0 || visited.find(1000*nx + ny)!=visited.end()) {
                    continue;
                }
                q.push({x+dx[i], y+dy[i], steps+1});
                visited.insert(1000*nx+ny);
            }
        }
        return -1;
    }
};