/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    const int dx[4] = {-1,0,1,0};
    const int dy[4] = {0,1,0,-1};
    set< pair<int,int> >visited;
    void goBack(Robot& robo) {
        robo.turnRight();
        robo.turnRight();
        robo.move();
        robo.turnRight();
        robo.turnRight();
    }
    
    void cleanRoom(Robot& robot) {
        backtrack(0, 0, 0, robot);
    }
    
    void backtrack(int x, int y, int dir, Robot& robo) {
        visited.insert({x,y});
        robo.clean();
        for(int i = 0; i < 4; ++i) {
            int ndir = (dir+i)%4;
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];
            if(visited.find({nx,ny}) == visited.end() && robo.move()) {
                backtrack(nx, ny, ndir, robo);
                goBack(robo);
            }
            robo.turnRight();
        }
    }
    
};