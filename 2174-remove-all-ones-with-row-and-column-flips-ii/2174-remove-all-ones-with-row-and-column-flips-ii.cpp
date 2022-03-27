class Solution {
public:
    int dp[16][16];
    int removeOnes(vector<vector<int>>& grid) {
        // memset(dp,-1,sizeof(dp));
        return solve(grid);
    }
    int solve(vector<vector<int>>& grid, int row = 0, int col = 0) {
        // if(dp[row][col] !=- 1) {
        //     return dp[row][col];
        // }
        int ans = 1e9;
        bool isOne = false;
        for(int i = 0; i < grid.size(); ++i) {
            if(row & (1<<i)) {
                continue;
            }
            for(int j = 0; j < grid[i].size(); ++j) {
                if(col & (1<<j)) {
                    continue;
                }
                if(grid[i][j]) {
                    isOne = true;
                    ans = min(ans, 1 + solve(grid, row|(1<<i), col|(1<<j)));
                }
            }
        }
        if(!isOne) {
            return 0;
        }
        return ans;
    }
    
};