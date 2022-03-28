const pair<int,int> dirs[] = {{-1,0},{0,-1},{0,1},{1,0}};
class Solution {
public:
    vector<vector<int>>grid;
    int rows, cols;
    int ans;
    map<pair<int,int>,int>dp;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        grid = matrix;
        rows = matrix.size(); cols = matrix[0].size();
        ans = 0;
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                dfs(i,j,-1);
                ans = max(ans,dp[{i,j}]);
            }
        }
        return ans;
    }
    int dfs(int x, int y, int last) {
        if(x<0||y<0||x>=rows||y>=cols||last>=grid[x][y])
            return 0;
        if(dp.find({x,y})!=dp.end())
            return dp[{x,y}];
        int val = 1;
        for(auto dir:dirs) {
            val = max(val,1+dfs(x+dir.first,y+dir.second,grid[x][y]));
        }
        return dp[{x,y}] = val;
       
    }
};