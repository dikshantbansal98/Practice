class Solution {
public:
    int maxA(int n) {
        vector<int>dp(n+1);
        if(n<=3) {
            return n;
        }
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; ++i) {
            dp[i] = dp[i-1]+1;
            for(int j = 1; j < i-2; ++j) {
                dp[i] = max(dp[i], dp[j] + dp[j]*(i-j-2));
            }
        }
        return dp[n];
    }
};