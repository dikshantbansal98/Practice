class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size(), cols = dungeon[0].size();
        vector<vector<int>>dp(rows+1,vector<int>(cols+1,1e9));
        for(int i = rows-1; i >= 0; --i) {
            for(int j = cols-1; j >= 0; --j){
                if(i==rows-1&&j==cols-1){
                    dp[i][j] = max(-dungeon[i][j]+1,1);
                    continue;
                }
                int optionRight = max(1,dp[i][j+1]-dungeon[i][j]);
                int optionDown = max(1,dp[i+1][j]-dungeon[i][j]);
                dp[i][j] = min(optionRight,optionDown);
                
            }
        }
        return dp[0][0];
    }
};