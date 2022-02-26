class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int dp[m+2][n+2][4];
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (mat[i-1][j-1]) {
                    dp[i][j][0] = dp[i-1][j][0] + mat[i-1][j-1]; // up
                    dp[i][j][1] = dp[i][j-1][1] + mat[i-1][j-1]; // left
                    dp[i][j][2] = dp[i-1][j-1][2] + mat[i-1][j-1]; // diag
                    dp[i][j][3] = dp[i-1][j+1][3] + mat[i-1][j-1]; // adiag
                }
                ans = max(ans, *max_element(dp[i][j], dp[i][j]+4));
            }
        }
        return ans;
    }
};