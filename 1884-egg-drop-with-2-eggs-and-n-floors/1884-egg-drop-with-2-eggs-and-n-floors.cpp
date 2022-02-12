class Solution {
public:
    int twoEggDrop(int n) {

        vector<int>dp(n+1,1);
        for(int i = 1; i <= n; ++i) {
            dp[i] = i;
        }
        for(int i = 2; i <= n; ++i) {
            for(int x = 2; x <= i-1; ++x) {
                dp[i] = min(dp[i],max(x-1,dp[i-x])+1);
            }
        }
        return dp[n];
    }
};